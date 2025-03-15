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
struct SegmentTree
{
    struct Node
    {
        int sum, lazy;

        Node() : sum(0), lazy(0) {}
        Node(int sum, int lazy) : sum(sum), lazy(lazy) {}

        Node operator + (const Node& other) const
        {
            Node res;
            res.sum = max(sum, other.sum);
            return res;
        }
    };
    int n;
    vector<Node> st;

    SegmentTree(int n) : n(n) { st.resize(4 * n + 5); }

    void pass(int head, int l, int r)
    {
        if (st[head].lazy == 0)
            return;

        st[head].sum += st[head].lazy;
        if (l != r)
        {
            st[2 * head].lazy += st[head].lazy;
            st[2 * head + 1].lazy += st[head].lazy;
        }

        st[head].lazy = 0;
    }

    void update(int head, int l, int r, int u, int v, int val)
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
    void update(int u, int v, int val)
    {
        if (u > v)
            return;
        update(1, 1, n, u, v, val);
    }

    int query(int head, int l, int r, int u, int v)
    {
        pass(head, l, r);
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return st[head].sum;

        int mid = l + r >> 1;
        return max(query(2 * head, l, mid, u, v), query(2 * head + 1, mid + 1, r, u, v));
    }
    int query(int u, int v)
    {
        if (u > v)
            return 0;
        return query(1, 1, n, u, v);
    }
};

void solve()
{
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> cnt(n + 1, 0);
    vector<int> suff(n + 2, 0);
    for (int i = n; i > 0; i--)
    {
        suff[i] = suff[i + 1] + (cnt[a[i]] == 0);
        cnt[a[i]] = 1;
    }

    int res = 0;
    vector<int> pos(n + 1, 0);
    pos[a[1]] = 1;
    SegmentTree st(n);
    st.update(1, 1, 1);
    set<int> distinct;
    distinct.insert(a[1]);
    for (int j = 2; j < n; j++)
    {
        distinct.insert(a[j]);
        st.update(pos[a[j]], j - 1, 1);
        st.update(j, j, distinct.size());
        pos[a[j]] = j;
        res = max(res, suff[j + 1] + st.query(1, j - 1));
    }

    cout << res << '\n';
}
