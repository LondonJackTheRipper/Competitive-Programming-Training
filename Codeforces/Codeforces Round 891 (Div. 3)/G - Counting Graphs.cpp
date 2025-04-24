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
const int mod = 998244353;

int mul(int a, int b) { return 1ll * a * b % mod; }
int power(int a, ll b)
{
    int res = 1;
    a %= mod;
    while (b)
    {
        if (b % 2 == 1)
            res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

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

    void merge(int u, int v, int w, ll &res)
    {
        u = find(u);
        v = find(v);
        if (u == v) return;

        res = 1ll * sz[u] * sz[v];

        if (sz[u] > sz[v]) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
    }
};

struct Edge
{
    int u, v, w;

    Edge() : u(0), v(0), w(0) {};
    Edge(int u, int v, int w) : u(u), v(v), w(w) {};
    bool operator < (const Edge& other) const
    {
        return w < other.w;
    }
};

void solve()
{
    int n, s; cin >> n >> s;
    vector<Edge> edges(n - 1);
    for (Edge &it : edges)
        cin >> it.u >> it.v >> it.w;

    sort(edges.begin(), edges.end());
    map<int, ll> cnt, val;
    DSU dsu(n);
    for (Edge e : edges)
    {
        int u = e.u, v = e.v, w = e.w;

        ll add = 0;
        dsu.merge(u, v, w, add);
        cnt[w] += add;
        val[w]++;
    }

    int ans = 1;
    for (auto it : cnt)
        ans = mul(ans, power(s - it.first + 1, it.second - val[it.first]));

    cout << ans << '\n';
}
