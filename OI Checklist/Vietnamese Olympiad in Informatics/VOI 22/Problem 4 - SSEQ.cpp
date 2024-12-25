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
const ll oo = 1e18;
const int maxn = 1e6 + 9;

struct SegmentTree
{
    int n;
    struct Node
    {
        ll mn, lazy;

        Node() = default;
        Node(ll mn, ll lazy) : mn(mn), lazy(lazy) {}

        Node operator + (const Node& other)
        {
            Node res;

            res.mn = min(mn, other.mn);

            return res;
        }
    };
    vector<Node> st;

    SegmentTree(int n) : n(n) { st.resize(4 * n + 10); }

    void pass(int head, int l, int r)
    {
        if (st[head].lazy == 0) return;

        ll &tmp = st[head].lazy;
        st[head].mn += tmp;

        if (l != r)
        {
            st[2 * head].lazy += tmp;
            st[2 * head + 1].lazy += tmp;
        }

        tmp = 0;
    }

    void update(int head, int l, int r, int u, int v, ll val)
    {
        pass(head, l, r);
        if (l > v || r < u) return;
        if (u <= l && r <= v)
        {
            st[head].lazy += val;
            pass(head, l, r);
            return;
        }

        int mid = l + r >> 1;
        update(2 * head, l, mid, u, v, val);
        update(2 * head + 1, mid + 1, r, u, v, val);

        st[head] = st[2 * head] + st[2 * head + 1];
    }
    void update(int u, int v, ll val) { update(1, 1, n, u, v, val); }

    ll query(int head, int l, int r, int u, int v)
    {
        pass(head, l, r);
        if (l > v || r < u) return oo;
        if (u <= l && r <= v) return st[head].mn;

        int mid = l + r >> 1;
        return min(query(2 * head, l, mid, u, v), query(2 * head + 1, mid + 1, r, u, v));
    }
    ll query(int u, int v) { return query(1, 1, n, u, v); }
};

struct Seg
{
    int l, r, w;

    Seg() = default;
    Seg(int l, int r, int w) : l(l), r(r), w(w) {};

    bool operator < (const Seg& other) const
    {
        return r < other.r;
    }
};

void solve()
{
    int n; cin >> n;
    vector<Seg> segs;
    for (int i = 0; i < n; i++)
    {
        int l, r, w; cin >> l >> r >> w;

        segs.push_back({l, r, w});
    }
    sort(segs.begin(), segs.end());

    int i = 0;
    ll pre = 0, res = 0;
    SegmentTree st(maxn);
    for (int i = 1; i <= (int)1e6; i++)
    {
        while (i < n && segs[i].r == i)
        {
            pre++;
            st.update(segs[i].l, i, segs[i].w);
        }

        res = max(res, pre - st.query(1, i));
    }

    cout << res << '\n';
}
