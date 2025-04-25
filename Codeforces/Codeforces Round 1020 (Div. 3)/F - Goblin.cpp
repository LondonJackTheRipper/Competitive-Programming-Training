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
    vector<ll> nodes;

    DSU(int n) : n(n)
    {
        nodes.resize(n + 2, 0);
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
        nodes[v] += nodes[u];
    }
};

struct Part
{
    int u, v, idx;

    Part() : u(0), v(0), idx(0) {};
    Part(int u, int v, int idx) : u(u), v(v), idx(idx) {};
};

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    DSU dsu(2 * n);
    vector<Part> prev;
    for (int i = 1; i <= n; i++)
    {
        char c = s[i - 1];

        vector<Part> cur;
        if (c == '1')
            cur.push_back(Part(i, i, 2 * (i - 1) + 1));
        else
        {
            if (i != 1)
                cur.push_back(Part(1, i - 1, 2 * (i - 1) + 1));
            if (i != n)
                cur.push_back(Part(i + 1, n, 2 * i));
        }

        for (Part it1 : cur)
        {
            int u1 = it1.u, v1 = it1.v, idx1 = it1.idx;
            dsu.nodes[idx1] = v1 - u1 + 1;
            for (Part it2 : prev)
            {
                int u2 = it2.u, v2 = it2.v, idx2 = it2.idx;

                if (!(v1 < u2 || v2 < u1))
                    dsu.merge(idx1, idx2);
            }
        }
        prev = cur;
    }

    ll res = 0;
    for (int i = 1; i <= 2 * n; i++)
        res = max(res, dsu.nodes[i]);

    cout << res << '\n';
}
