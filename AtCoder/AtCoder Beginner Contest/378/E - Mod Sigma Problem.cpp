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
};

void solve()
{
    int n, m; cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] %= m;
    int prefix[n + 1];
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + (a[i] % m);
        if (prefix[i] >= m)
            prefix[i] -= m;
    }

    int X[n + 1];
    FenwickTree bit(m);
    for (int i = 1; i <= n; i++)
    {
        X[i] = i - 1 - bit.query(prefix[i] + 1);

        bit.update(prefix[i] + 1, 1);
    }

    ll pre = 0, res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += 1ll * i * prefix[i] - pre + 1ll * m * X[i];

        pre += prefix[i];
    }

    cout << res << '\n';
}
