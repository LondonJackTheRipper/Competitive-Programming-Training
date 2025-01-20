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

    bool can_merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        return (u != v);
    }

    bool merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v) return false;

        if (sz[u] > sz[v]) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
        return true;
    }
};

void solve()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<pair<int, int>> e1(m1), e2(m2);
    for (pair<int, int> &it : e1)
        cin >> it.first >> it.second;
    DSU dsu(n);
    for (pair<int, int> &it : e2)
    {
        cin >> it.first >> it.second;
        dsu.merge(it.first, it.second);
    }

    DSU dsu1(n);
    int res = 0;
    for (pair<int, int> it : e1)
    {
        if (dsu.can_merge(it.first, it.second))
            res++;
        else
            dsu1.merge(it.first, it.second);
    }
    for (pair<int, int> it : e2)
        if (dsu1.merge(it.first, it.second))
            res++;

    cout << res << '\n';
}
