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
const int maxn = 1001;

int n;
vector<int> adj[maxn];
ll x[maxn], y[maxn], r[maxn];

bool tagnent(int i, int j)
{
    return ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) == r[i] * r[i] + 2 * r[i] * r[j] + r[j] * r[j]);
}

bool bipartite;
int col[maxn], cnt[2];
void DFS(int u, int c)
{
    cnt[c]++;
    col[u] = c;
    for (int v : adj[u])
    {
        if (col[v] == -1)
            DFS(v, 1 ^ c);
        else
        if (col[v] == col[u])
            bipartite = false;
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
        col[i] = -1;
    }

    // construct graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (tagnent(i, j))
                adj[i].push_back(j);

    for (int i = 1; i <= n; i++)
    {
        if (col[i] != -1)
            continue;

        bipartite = true;
        cnt[0] = cnt[1] = 0;
        DFS(i, 0);

        if (bipartite == true && cnt[0] != cnt[1])
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}
