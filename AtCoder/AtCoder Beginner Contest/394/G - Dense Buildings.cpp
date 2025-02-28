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
const int maxn = 501;
const int maxq = 2e5 + 1;
const int maxval = 1e6;

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

int h, w, q;
int f[maxn][maxn], a[maxq], b[maxq], y[maxq], c[maxq], d[maxq], z[maxq], l[maxq], r[maxq];
vector<pair<int, int>> edges[maxval + 1];
vector<int> queries[maxval + 1];

int dx[2] = {-1, 0};
int dy[2] = {0, -1};
int encode(int i, int j) { return (i - 1) * w + j; }
bool isin(int i, int j) { return (1 <= min(i, j) && i <= h && j <= w); }

void solve()
{
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            cin >> f[i][j];
            for (int d = 0; d < 2; d++)
            {
                int ii = i + dx[d];
                int jj = j + dy[d];

                if (!isin(ii, jj))
                    continue;
                int u = encode(i, j), v = encode(ii, jj);
                edges[min(f[i][j], f[ii][jj])].push_back({u, v});
            }
        }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> a[i] >> b[i] >> y[i] >> c[i] >> d[i] >> z[i];
        l[i] = 1;
        r[i] = maxval + 1;
    }

    while (true)
    {
        bool flag = false;
        for (int i = 0; i <= maxval; i++)
            queries[i].clear();
        for (int i = 1; i <= q; i++)
        {
            if (r[i] - l[i] <= 1)
                continue;
            flag = true;
            queries[l[i] + r[i] >> 1].push_back(i);
        }
        if (flag == false)
            break;

        DSU dsu(h * w);
        for (int i = maxval; i >= 0; i--)
        {
            for (pair<int, int> it : edges[i])
                dsu.merge(it.first, it.second);

            if (queries[i].empty())
                continue;
            for (int x : queries[i])
            {
                int u = encode(a[x], b[x]), v = encode(c[x], d[x]);

                if (dsu.find(u) == dsu.find(v))
                    l[x] = i;
                else
                    r[x] = i;
            }
        }
    }

    for (int i = 1; i <= q; i++)
        cout << y[i] + z[i] - 2 * min({y[i], z[i], l[i]}) << '\n';
}
