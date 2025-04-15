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
struct DSU
{
    int n;
    vector<int> par, sz;

    DSU(int n) : n(n)
    {
        par.resize(n + 2, 0);
        sz.resize(n + 2, 1);
        for (int i = 1; i <= n; i++) par[i] = i;
    }

    int find(int u) { return (u == par[u] ? u : par[u] = find(par[u])); }

    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v) return;

        if (sz[u] > sz[v]) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
    }
};

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << adj[1].size() << '\n';
    int cur = adj[1].size();
    set<int> se;
    for (int v : adj[1]) se.insert(v);
    if (se.find(1) != se.end())
        se.erase(1);
    DSU dsu(n);
    for (int i = 2; i <= n; i++)
    {
        for (int j : adj[i])
        {
            if (j <= i)
                dsu.merge(i, j);
            else
                se.insert(j);
        }

        if (se.find(i) != se.end())
            se.erase(i);

        cout << (dsu.sz[dsu.find(1)] != i ? -1 : (int)se.size()) << '\n';
    }
}
