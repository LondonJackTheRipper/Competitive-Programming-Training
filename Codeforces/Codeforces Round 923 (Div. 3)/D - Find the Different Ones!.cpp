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

    struct Node
    {
        int mn, mx;
        int idx1, idx2;

        Node() = default;
        Node(int mn, int mx, int idx1, int idx2) : mn(mn), mx(mx), idx1(idx1), idx2(idx2) {};

        Node operator + (const Node& other)
        {
            Node res;

            if (idx1 == -1) return other;
            if (other.idx1 == -1) return *this;

            res.mn = min(mn, other.mn);
            res.mx = max(mx, other.mx);
            res.idx1 = (mn < other.mn ? idx1 : other.idx1);
            res.idx2 = (mx > other.mx ? idx2 : other.idx2);

            return res;
        }
    };
    vector<Node> st;

    SegmentTree(int n, int *arr) : n(n)
    {
        st.resize(4 * n + 10);
        build(1, 1, n, arr);
    }

    void build(int head, int l, int r, int *arr)
    {
        if (l == r)
        {
            st[head] = Node(arr[l], arr[l], l, l);
            return;
        }

        int mid = l + r >> 1;

        build(2 * head, l, mid, arr);
        build(2 * head + 1, mid + 1, r, arr);

        st[head] = st[2 * head] + st[2 * head + 1];
    }

    Node query(int head, int l, int r, int u, int v)
    {
        if (l > v || r < u) return Node(0, 0, -1, 0);

        if (u <= l && r <= v) return st[head];

        int mid = l + r >> 1;
        return query(2 * head, l, mid, u, v) + query(2 * head + 1, mid + 1, r, u, v);
    }
    pair<int, int> query(int u, int v)
    {
        Node res = query(1, 1, n, u, v);
        return {res.idx1, res.idx2};
    }
};

void solve()
{
    int n; cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];

    SegmentTree st(n, arr);

    int q; cin >> q;
    while (q--)
    {
        int l, r; cin >> l >> r;

        pair<int, int> res = st.query(l, r);

        if (res.first == res.second || arr[res.first] == arr[res.second])
            res.first = res.second = -1;

        cout << res.first << ' ' << res.second << '\n';
    }
}
