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
const int oo = 2e9;
const int maxn = 2e5 + 9;

vector<int> adj[maxn];
int del[maxn], sz[maxn], deg[maxn];
int n, res, ans, mx;

int subtree(int u, int p = -1)
{
    sz[u] = 1;
    for (int v : adj[u])
        if (!del[v] && v != p)
            sz[u] += subtree(v, u);
    return sz[u];
}

int find_centroid(int u, int p, int N)
{
    for (int v : adj[u])
        if (v != p && !del[v] && sz[v] > N / 2)
            return find_centroid(v, u, N);
    return u;
}

void proc(int u, int p, int pre, bool flag)
{
    if (flag)
        mx = max(mx, pre);
    else
        res = max(res, pre + mx);

    for (int v : adj[u])
        if (v != p && !del[v])
            proc(v, u, pre + deg[v], flag);
}

void centroid_decomposition(int u)
{
    int centroid = find_centroid(u, -1, subtree(u));
    del[centroid] = 1;
    res = -oo;
    mx = 0;

    for (int v : adj[centroid])
        if (!del[v])
        {
            proc(v, centroid, deg[v], false);
            proc(v, centroid, deg[v], true);
        }

    if (res != -oo)
        ans = max(ans, res + 2 + deg[centroid]);

    for (int v : adj[centroid])
        if (!del[v])
            centroid_decomposition(v);
}

void solve()
{
    cin >> n;
    res = ans = mx = 0;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        deg[i] = sz[i] = del[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, deg[i]);
        deg[i] -= 2;
    }

    centroid_decomposition(1);

    cout << ans << '\n';
}
