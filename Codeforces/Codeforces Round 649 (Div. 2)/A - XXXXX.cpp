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
const int oo = 1e9;

struct SegmentTree
{
    int n;
    vector<int> st;

    SegmentTree(int n) : n(n) { st.resize(4 * n + 5, oo); }

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

        st[head] = min(st[2 * head], st[2 * head + 1]);
    }
    void update(int pos, int val) { update(1, 1, n, pos, val); }

    int query(int head, int l, int r, int u, int v)
    {
        if (l > v || r < u) return oo;
        if (u <= l && r <= v) return st[head];

        int mid = l + r >> 1;
        return min(query(2 * head, l, mid, u, v), query(2 * head + 1, mid + 1, r, u, v));
    }
    int query(int u, int v) { if (u > v) return oo; return query(1, 1, n, u, v); }
};

void solve()
{
    int n, x; cin >> n >> x;

    SegmentTree seg(x + 1);
    vector<int> used(x + 1, 0);
    int pre = 0, res = -1;
    seg.update(1, 0);
    used[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int v; cin >> v;
        pre = (pre + v) % x;

        int mn = min(seg.query(pre + 2, x), seg.query(1, pre));
        if (mn != oo)
            res = max(res, i - mn);

        if (used[pre] == 0)
        {
            used[pre] = 1;
            seg.update(pre + 1, i);
        }
    }

    cout << res << '\n';
}
