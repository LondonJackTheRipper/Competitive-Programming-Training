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
struct Tree
{
    int n, diameter;
    vector<vector<int>> adj;
    vector<int> h, par, mx;

    Tree(int n, vector<vector<int>> adjacent) : n(n), adj(adjacent)
    {
        h.resize(n + 1, 0);
        par.resize(n + 1, 0);
        mx.resize(n + 1, 0);

        Process();
    }

    int fi = 1, se = 1;
    void DFS(int u, int p = -1)
    {
        if (h[u] > h[fi])
            fi = u;
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            h[v] = h[u] + 1;
            par[v] = u;
            DFS(v, u);
        }
    }
    void DFS_MAIN(int u, int p, int core)
    {
        mx[u] = mx[core] + h[u];
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            h[v] = h[u] + 1;
            DFS_MAIN(v, u, core);
        }
    }

    void Process()
    {
        DFS(1);
        se = fi;
        h[fi] = par[fi] = 0;
        DFS(fi);
        swap(fi, se);

        int cur = se;
        diameter = h[se];
        while (cur)
        {
            mx[cur] = max(h[cur], diameter - h[cur]);

            h[cur] = 0;
            for (int v : adj[cur])
                if (v != par[cur] && h[v] != 0)
                {
                    h[v] = 1;
                    DFS_MAIN(v, cur, cur);
                }

            cur = par[cur];
        }
    }
};

void solve()
{
    int n1; cin >> n1;
    vector<vector<int>> adj1(n1 + 1, vector<int>());
    for (int i = 1; i < n1; i++)
    {
        int u, v; cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    Tree t1(n1, adj1);
    vector<int> res1 = t1.mx;
    int d1 = t1.diameter;

    int n2; cin >> n2;
    vector<vector<int>> adj2(n2 + 1, vector<int>());
    for (int i = 1; i < n2; i++)
    {
        int u, v; cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    Tree t2(n2, adj2);
    vector<int> res2 = t2.mx;
    sort(res2.begin(), res2.end());
    vector<ll> prefix(res2.begin(), res2.end());
    for (int i = 2; i <= n2; i++)
        prefix[i] += prefix[i - 1];
    int d2 = t2.diameter;

    ll res = 0;
    int mx = max(d1, d2);
    for (int i = 1; i <= n1; i++)
    {
        int pos = lower_bound(res2.begin() + 1, res2.begin() + n2 + 1, mx - 1 - res1[i]) - res2.begin();

        res += 1ll * (pos - 1) * mx;
        res += prefix[n2] - prefix[pos - 1];
        res += 1ll * (n2 - pos + 1) * (res1[i] + 1);
    }

    cout << res << '\n';
}
