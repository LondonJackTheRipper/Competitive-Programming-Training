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

    struct Node
    {
        ll sum;
        int lazy;

        Node(ll sum = 0, int lazy = 0) : sum(sum), lazy(lazy) {};

        Node operator + (const Node& other)
        {
            Node res;

            res.sum = sum + other.sum;

            return res;
        }
    };
    vector<Node> st;

    SegmentTree(int n) : n(n) { st.resize(4 * n + 10); }

    void pass(int head, int l, int r)
    {
        if (st[head].lazy == 0) return;

        st[head].sum += 1ll * st[head].lazy * (r - l + 1);

        if (l != r)
        {
            st[2 * head].lazy += st[head].lazy;
            st[2 * head + 1].lazy += st[head].lazy;
        }

        st[head].lazy = 0;
    }

    void update(int head, int l, int r, int u, int v)
    {
        pass(head, l, r);
        if (l > v || r < u) return;
        if (u <= l && r <= v)
        {
            st[head].lazy++;
            pass(head, l, r);
            return;
        }

        int mid = l + r >> 1;
        update(2 * head, l, mid, u, v);
        update(2 * head + 1, mid + 1, r, u, v);

        st[head] = st[2 * head] + st[2 * head + 1];
    }
    void update(int u, int v) { update(1, 1, n, u, v); }

    ll query(int head, int l, int r, int u, int v)
    {
        pass(head, l, r);
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return st[head].sum;

        int mid = l + r >> 1;
        return query(2 * head, l, mid, u, v) + query(2 * head + 1, mid + 1, r, u, v);
    }
    ll query(int u, int v) { return query(1, 1, n, u, v); }
};

void solve()
{
    int n; cin >> n;

    SegmentTree st(n);
    vector<int> pos(n + 1, 0);
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;

        st.update(pos[x] + 1, i);
        pos[x] = i;

        res += st.query(1, i);
    }

    cout << res << '\n';
}
