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
    int n; cin >> n;
    int cnt_odd = 0;
    vector<int> parity(n + 1);
    for (int i = 1; i <= n; i++)
    {
        char c; cin >> c;
        parity[i] = (c - '0');
        cnt_odd += (parity[i] % 2 == 1);
    }
    if (cnt_odd == 0 || cnt_odd % 2 == 1)
    {
        cout << "NO\n";
        return;
    }

    DSU dsu(n);
    vector<int> adj[n + 1];
    for (int i = 2; i <= n; i++)
        if (parity[i - 1] == 0 && parity[i] == 0)
        {
            dsu.merge(i, i - 1);
            adj[i - 1].push_back(i);
            adj[i].push_back(i - 1);
        }
    if (parity[n] == parity[1] && parity[n] == 0)
    {
        dsu.merge(1, n);
        adj[1].push_back(n);
        adj[n].push_back(1);
    }
    for (int i = 1; i <= n; i++)
    {
        int prev = (i == 1 ? n : i - 1);
        if (parity[prev] == 0 && parity[i] == 1 && dsu.sz[i] == 1)
        {
            dsu.merge(prev, i);
            adj[prev].push_back(i);
            adj[i].push_back(prev);
        }
    }
    int cnt = 0;
    vector<int> deg(2, 0), need;
    for (int i = 1; i <= n; i++)
    {
        cnt += (dsu.find(i) == i);
        if ((int)adj[i].size() != 0 && ((int)adj[i].size() % 2) == parity[i])
            continue;
        need.push_back(i);
        deg[abs((int)adj[i].size() - parity[i]) % 2] = i;
    }
    int core = deg[((int)need.size() - 1) % 2];
    for (int x : need)
    {
        if (x == core)
            continue;
        adj[x].push_back(core);
        adj[core].push_back(x);
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        for (int x : adj[i])
            if (x > i)
                cout << i << ' ' << x << '\n';
}
