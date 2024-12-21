#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
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
const int maxn = 3e5 + 9;

vector<int> adj[maxn];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int mn = 1e9;
    for (int u = 1; u <= n; u++)
    {
        vector<int> g;
        for (int v : adj[u])
            if (adj[v].size() != 1)
                g.push_back(adj[v].size() - 1);
        sort(g.begin(), g.end());

        int nn = g.size();

        for (int i = 1; i <= nn; i++)
            mn = min(mn, n - (1 + (g[i - 1] + 1) * (nn - i + 1)));
    }

    cout << mn << '\n';
}
