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
    int n, m; cin >> n >> m;
    int a[n + 1];
    vector<int> left(n + 1, 0), right(n + 1, 0), cnt(m + 1, 0);
    vector<int> pos[m + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        pos[m - a[i]].push_back(i);
        left[i] = i - cnt[a[i]];
    }
    ll st = 0;
    FenwickTree bit(m);
    for (int i = n; i > 0; i--)
    {
        right[i] = n - i - bit.query(a[i] + 1, a[i] + 1);
        if (a[i] != 0)
            st += bit.query(a[i]);
        bit.update(a[i] + 1, 1);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j : pos[i])
            st += left[j] - right[j];
        cout << st << '\n';
    }
}
