#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
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
const int maxn = 2e5 + 9;

vector<int> adj[maxn];
int dp_x[maxn], dp_y[maxn], deg[maxn];
int n;

void DP_DFS(int u, int p = -1, int mx1 = -1, int mx2 = -1)
{
    dp_x[u] = deg[u];
    for (int v : adj[u])
    {
        if (v == p)
            continue;

        DP_DFS(v, u);
        dp_x[u] = max(dp_x[u], dp_x[v] + deg[u] - 2);

        mx2 = max(mx2, dp_x[v] + deg[u] - 2);
        if (mx2 > mx1)
            swap(mx2, mx1);
    }

    if (mx2 != -1)
        dp_y[u] = mx1 + mx2 - deg[u];
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        dp_x[i] = dp_y[i] = deg[i] = 0;
        adj[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    DP_DFS(1);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max({ans, dp_x[i], dp_y[i]});

    cout << ans << '\n';
}
