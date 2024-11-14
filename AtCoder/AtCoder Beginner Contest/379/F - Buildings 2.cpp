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
struct FenwickTree
{
    int n;
    vector<int> bits;

    FenwickTree(int n) : n(n) { bits.resize(n + 1, 0); }

    void update(int pos, int val)
    {
        for (; pos <= n; pos += (pos & (-pos)))
            bits[pos] += val;
    }

    int query(int pos)
    {
        int res = 0;
        for (; pos > 0; pos -= (pos & (-pos)))
            res += bits[pos];
        return res;
    }
    int query(int l, int r) { return query(r) - query(l - 1); }
};

void solve()
{
    int n, q; cin >> n >> q;
    int h[n], res[n], ans[q];
    vector<pair<int, int>> qrs[n + 1];
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < q; i++)
    {
        int l, r; cin >> l >> r;
        qrs[l].push_back({r, i});
    }

    stack<int> st;
    st.push(n - 1);
    FenwickTree bit(n);
    bit.update(n, 1);
    for (int i = n - 2; i >= 0; i--)
    {
        int l = i + 1;
        for (pair<int, int> Q : qrs[l])
        {
            int r = Q.first;
            ans[Q.second] = st.size() - bit.query(l, r);
        }

        while (!st.empty() && h[i] > h[st.top()])
        {
            bit.update(st.top() + 1, -1);
            st.pop();
        }
        st.push(i);
        bit.update(i + 1, 1);
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}
