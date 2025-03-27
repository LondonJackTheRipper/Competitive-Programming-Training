#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

const string name = "test";

void solve();
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}

// main program
const int maxn = 100;

vector<int> adj[maxn + 1];
int par[8][maxn + 1], h[maxn + 1];
int n;

void DFS(int u, int p = -1)
{
    for (int v : adj[u])
    {
        if (v == p)
            continue;

        h[v] = h[u] + 1;
        par[0][v] = u;
        for (int i = 1; i < 8; i++)
            par[i][v] = par[i - 1][par[i - 1][v]];
        DFS(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int k = h[u] - h[v];
    for (int i = 0; i < 8; i++)
        if (k >> i & 1)
            u = par[i][u];

    if (u == v) return u;

    for (int i = 7; i >= 0; i--)
        if (par[i][u] != par[i][v])
        {
            u = par[i][u];
            v = par[i][v];
        }
    return par[0][u];
}

void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1);
    int cnt = 0;
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            int dist = h[i] + h[j] - 2 * h[LCA(i, j)];

            if (dist != 1 && dist % 2 == 1)
            {
                mp[{i, j}] = 1;
                cnt++;
            }
        }

    string response = "Second";
    if (cnt % 2 == 1)
        response = "First";
    cout << response << endl;
    if (response == "Second")
    {
        int i, j; cin >> i >> j;
        mp[{i, j}] = 0;
    }
    int turns = 0;
    while (1)
    {
        if (turns == 0)
        {
            for (auto it : mp)
                if (it.second != 0)
                {
                    int i = it.first.first, j = it.first.second;
                    cout << i << ' ' << j << endl;
                    mp[{i, j}] = 0;
                    break;
                }
        } else
        {
            int i, j; cin >> i >> j;
            if (i == -1)
                return;
            mp[{i, j}] = 0;
        }
        turns ^= 1;
    }
}
