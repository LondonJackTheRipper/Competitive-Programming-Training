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

void solve()
{
    int n; cin >> n;
    ll c; cin >> c;
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        sum2 += x * x;
        sum1 += x;
    }

    ll l = 1, r = 1e9;
    while (l <= r)
    {
        ll mid = (l + r) / 2;

        ll cur = 2 * sum1 + n * mid;
        if (cur == (c - sum2) / mid)
        {
            cout << mid / 2 << '\n';
            return;
        } else
        if (cur < (c - sum2) / mid)
            l = mid + 1;
        else
            r = mid - 1;
    }
}
