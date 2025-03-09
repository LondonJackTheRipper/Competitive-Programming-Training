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
const int maxn = 10;

vector<pair<int, ll>> adj[maxn + 1];
int n, m;
ll ans = 1160000000000000000;

void gen(int u, ll w, vector<int> visited)
{
    visited[u] = 1;
    if (u == n)
    {
        ans = min(ans, w);
        return;
    }

    for (pair<int, ll> nxt : adj[u])
    {
        int v = nxt.first;

        if (visited[v] == 1)
            continue;

        gen(v, w ^ nxt.second, visited);
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        ll w; cin >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> visited(n + 1, 0);
    gen(1, 0, visited);

    cout << ans << '\n';
}
