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
const int maxn = 2e5 + 9;

vector<int> adj[maxn], group[maxn];
int n;

ll C(int n) { return 1ll * n * (n - 1) / 2; }

struct DSU
{
    int n;
    vector<int> par, sz;

    DSU(int n) : n(n)
    {
        par.resize(n + 1, 0);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) par[i] = i;
    }

    int find(int u) { return (u == par[u] ? u : par[u] = find(par[u])); }

    bool merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[u] > sz[v]) swap(u, v);
        sz[v] += sz[u];
        par[u] = v;
        return true;
    }
};

void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DSU dsu(n);
    for (int u = 1; u <= n; u++)
    {
        if (adj[u].size() != 3) continue;

        for (int v : adj[u])
        {
            if (adj[v].size() != 3) continue;

            dsu.merge(u, v);
        }
    }
    for (int u = 1; u <= n; u++)
    {
        if (adj[u].size() != 3) continue;

        group[dsu.find(u)].push_back(u);
    }

    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (group[i].empty()) continue;

        int num = 0;

        for (int u : group[i])
        {
            for (int v : adj[u])
                num += (adj[v].size() == 2);
        }

        res += C(num);
    }

    cout << res << '\n';
}
