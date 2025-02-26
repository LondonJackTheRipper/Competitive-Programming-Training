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
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int total = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            total += (a[i] > a[j]);

    int ans = total;
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++)
    {
        int still_pre = 0, pre = 0;
        FenwickTree bit1(2001), bit2(2001);
        bit1.update(a[i], 1);
        for (int j = i + 1; j <= n; j++)
        {
            still_pre += j - i - bit1.query(a[j]);
            bit1.update(a[j], 1);

            pre += j - i - 1 - bit2.query(a[j]);
            if (ans > total - still_pre + pre + j - i - 1 - bit2.query(a[i]))
            {
                ans = total - still_pre + pre + j - i - 1 - bit2.query(a[i]);
                l = i;
                r = j;
            }
            bit2.update(a[j], 1);
        }
    }

    cout << l << ' ' << r << '\n';
}
