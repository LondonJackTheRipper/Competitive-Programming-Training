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
struct SegmentTree
{
    int n;
    vector<int> st;

    SegmentTree(int n, vector<int>& deg) : n(n)
    {
        st.resize(4 * n + 5, 0);
        build(1, 1, n, deg);
    }

    void build(int head, int l, int r, vector<int>& deg)
    {
        if (l == r)
        {
            st[head] = deg[l];
            return;
        }

        int mid = l + r >> 1;
        build(2 * head, l, mid, deg);
        build(2 * head + 1, mid + 1, r, deg);

        st[head] = max(st[2 * head], st[2 * head + 1]);
    }

    void update(int head, int l, int r, int pos, int val)
    {
        if (pos < l | r < pos) return;
        if (l == r)
        {
            st[head] = val;
            return;
        }

        int mid = l + r >> 1;
        if (pos <= mid)
            update(2 * head, l, mid, pos, val);
        else
            update(2 * head + 1, mid + 1, r, pos, val);

        st[head] = max(st[2 * head], st[2 * head + 1]);
    }
    void update(int pos, int val) { update(1, 1, n, pos, val); }

    int query(int head, int l, int r, int u, int v)
    {
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return st[head];

        int mid = l + r >> 1;
        return max(query(2 * head, l, mid, u, v), query(2 * head + 1, mid + 1, r, u, v));
    }
    int query(int u, int v) { return query(1, 1, n, u, v); }
};

void solve()
{
    int n; cin >> n;
    vector<int> deg(n + 1, 0);
    vector<int> adj[n + 1];
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    int res = 0;
    SegmentTree st(n, deg);
    for (int i = 1; i <= n; i++)
    {
        for (int j : adj[i])
        {
            st.update(j, 0);
            res = max(res, deg[i] + deg[j] - 2);
        }
        st.update(i, 0);
        int qr = st.query(1, n);
        if (qr != 0)
            res = max(res, deg[i] + qr - 1);
        st.update(i, deg[i]);
        for (int j : adj[i])
            st.update(j, deg[j]);
    }

    cout << res << '\n';
}
