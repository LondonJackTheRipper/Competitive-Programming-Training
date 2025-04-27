#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

string name = "test";

void solve();
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

// main program
const int maxn = 1e5 + 1;

vector<int> adj[maxn];
int h[maxn];
int n, st, en;

void DFS(int u, int p = -1)
{
    for (int v : adj[u])
    {
        if (v == p)
            continue;

        h[v] = h[u] + 1;
        DFS(v, u);
    }
}

bool cmp(int a, int b) { return h[a] > h[b]; }

void solve()
{
    cin >> n >> st >> en;
    for (int i = 1; i <= n; i++)
    {
        h[i] = 0;
        adj[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(en);
    vector<int> li;
    for (int i = 1; i <= n; i++)
        li.push_back(i);
    sort(li. begin(), li.end(), cmp);

    for (int x : li)
        cout << x << ' ';
    cout << '\n';
}
