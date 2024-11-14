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
struct SegmentTree
{
    int n;
    vector<int> st, lazy;

    SegmentTree(int n) : n(n)
    {
        st.resize(4 * n + 10, 0);
        lazy.resize(4 * n + 10, -1);
    }

    void pass(int head, int l, int r)
    {
        if (lazy[head] == -1) return;

        st[head] = lazy[head];
        if (l != r)
        {
            lazy[2 * head] = lazy[head];
            lazy[2 * head + 1] = lazy[head];
        }

        lazy[head] = -1;
    }

    void update(int head, int l, int r, int u, int v, int val)
    {
        pass(head, l, r);
        if (l > v || r < u) return;
        if (u <= l && r <= v)
        {
            lazy[head] = val;
            pass(head, l, r);
            return;
        }

        int mid = l + r >> 1;

        update(2 * head, l, mid, u, v, val);
        update(2 * head + 1, mid + 1, r, u, v, val);

        st[head] = st[2 * head] + st[2 * head + 1];
    }
    void update(int u, int v, int val) { update(1, 1, n, u, v, val); }

    int query(int head, int l, int r, int u, int v)
    {
        pass(head, l, r);
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return st[head];

        int mid = l + r >> 1;

        return query(2 * head, l, mid, u, v) + query(2 * head + 1, mid + 1, r, u, v);
    }
    int query(int u, int v) { return query(1, 1, n, u, v); }
};

void solve()
{
    int n; cin >> n;
    int h[n + 1], high[n + 1];
    for (int i = 1; i <= n; i++) cin >> h[i];

    SegmentTree seg(n);
    for (int i = n; i > 0; i--)
    {
        high[i] = seg.query(1, n);
        seg.update(1, h[i], 0);
        seg.update(h[i], h[i], 1);
    }

    for (int i = 1; i <= n; i++)
        cout << high[i] << ' ';
    cout << '\n';
}
