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
const int maxn = 2e5 + 9;

int w, h, n;
struct bl
{
    int r, c, l, id;

    bl() = default;
    bl(int r, int c, int l, int id) : r(r), c(c), l(l), id(id) {};

    bool operator < (const bl &other) const
    {
        if (r == other.r)
            return c < other.c;
        return r < other.r;
    }
};
vector<bl> blocks;

struct SegmentTree
{
    int n;
    vector<int> st, lazy;

    SegmentTree(int n) : n(n)
    {
        st.resize(4 * n + 5, w);
        lazy.resize(4 * n + 5, -1);
    }

    void pass(int head, int l, int r)
    {
        if (lazy[head] == -1) return;

        int &tmp = lazy[head];
        st[head] = tmp;
        if (l != r)
        {
            lazy[2 * head] = tmp;
            lazy[2 * head + 1] = tmp;
        }

        tmp = -1;
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

        st[head] = min(st[2 * head], st[2 * head + 1]);
    }
    void update(int u, int v, int val) { update(1, 1, n, u, v, val); }

    int query(int head, int l, int r, int u, int v)
    {
        pass(head, l, r);
        if (l > v || r < u) return 1e9;
        if (u <= l && r <= v) return st[head];

        int mid = l + r >> 1;
        return min(query(2 * head, l, mid, u, v), query(2 * head + 1, mid + 1, r, u, v));
    }
    int query(int u, int v) { return query(1, 1, n, u, v); }
};

int ans[maxn];

void solve()
{
    cin >> w >> h >> n;
    for (int i = 0; i < n; i++)
    {
        int r, c, l; cin >> r >> c >> l;
        blocks.push_back({r, c, l, i});
    }
    sort(blocks.begin(), blocks.end());

    SegmentTree seg(h + 1);
    for (int i = n - 1; i >= 0; i--)
    {
        int r = blocks[i].r, c = blocks[i].c, l = blocks[i].l, id = blocks[i].id;
        int qr = seg.query(c, c + l - 1);
        ans[id] = qr;
        seg.update(c, c + l - 1, qr - 1);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
}
