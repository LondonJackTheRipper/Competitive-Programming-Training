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
    vector<ll> bits;

    FenwickTree(int n = 0) : n(n) { bits.resize(n + 1, 0); }

    void update(int pos, ll val)
    {
        for (; pos <= n; pos += (pos & (-pos)))
            bits[pos] += val;
    }

    ll query(int pos)
    {
        ll res = 0;
        for (; pos > 0; pos -= (pos & (-pos)))
            res += bits[pos];
        return res;
    }
};

void solve()
{
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    k++;
    FenwickTree BIT[k];
    for (int i = 0; i < k; i++)
        BIT[i] = FenwickTree(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = k - 1; j > 0; j--)
            BIT[j].update(a[i], BIT[j - 1].query(a[i]));
        BIT[0].update(a[i], 1);
    }

    cout << BIT[k - 1].query(n) << '\n';
}
