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
    vector<ll> st, lazy;

    SegmentTree(int n) : n(n)
    {
        st.resize(4 * n + 10, 0);
        lazy.resize(4 * n + 10, 0);
    }

    void pass(int head, int l, int r)
    {
        if (lazy[head] == 0) return;

        st[head] += (r - l + 1) * lazy[head];

        if (l != r)
        {
            lazy[2 * head] += lazy[head];
            lazy[2 * head + 1] += lazy[head];
        }

        lazy[head] = 0;
    }

    void update(int head, int l, int r, int u, int v, ll val)
    {
        pass(head, l, r);
        if (l > v || r < u) return;
        if (u <= l && r <= v)
        {
            lazy[head] += val;
            pass(head, l, r);
            return;
        }

        int mid = l + r >> 1;
        update(2 * head, l, mid, u, v, val);
        update(2 * head + 1, mid + 1, r, u, v, val);

        st[head] = st[2 * head] + st[2 * head + 1];
    }
    void update(int u, int v, ll val) { return update(1, 1, n, u, v, val); }

    ll get(int head, int l, int r, int pos)
    {
        pass(head, l, r);
        if (l == r)
            return st[head];

        int mid = l + r >> 1;

        if (pos <= mid)
            return get(2 * head, l, mid, pos);
        return get(2 * head + 1, mid + 1, r, pos);
    }
    ll get(int pos) { return get(1, 1, n, pos); }
};

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    SegmentTree seg(n);
    for (int i = 0; i < n; i++)
    {
        ll coff = i + 1;
        seg.update(1, n - i, coff * (s[i] - '0'));
    }
    vector<int> digit(1e6, 0);
    for (int i = 1; i <= n; i++)
    {
        ll coff = seg.get(i) + digit[i];
        digit[i] = coff % 10;
        coff /= 10;
        int turns = 1;
        while (coff)
        {
            digit[i + turns++] += (coff % 10);
            coff /= 10;
        }
    }

    bool start = false;
    for (int i = 1e6; i >= 1; i--)
    {
        if (digit[i] != 0) start = true;
        if (start)
            cout << digit[i];
    }
    cout << '\n';
}
