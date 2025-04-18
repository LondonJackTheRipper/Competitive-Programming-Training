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
    int n;
    vector<int> st;

    SegmentTree(int n, int *arr) : n(n)
    {
        st.resize(4 * n + 5, 0);
        build(1, 1, n, arr);
    }

    void build(int head, int l, int r, int *arr)
    {
        if (l == r)
        {
            st[head] = arr[l];
            return;
        }

        int mid = l + r >> 1;
        build(2 * head, l, mid, arr);
        build(2 * head + 1, mid + 1, r, arr);

        st[head] = max(st[2 * head], st[2 * head + 1]);
    }

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
    int n, m; cin >> n >> m;
    int a[m + 1];
    for (int i = 1; i <= m; i++)
        cin >> a[i];

    SegmentTree st(m, a);
    int q; cin >> q;
    while (q--)
    {
        int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;

        if ((abs(xs - xf) % k != 0) || (abs(ys - yf) % k != 0))
        {
            cout << "NO\n";
            continue;
        }

        int mx = xs + ((n - xs) / k) * k;
        if (ys > yf)
            swap(ys, yf);
        cout << (mx > st.query(ys, yf) ? "YES\n" : "NO\n");
    }
}
