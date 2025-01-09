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
    ll h; cin >> h;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll l = 1, r = 1e18;
    ll res = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        ll damage = mid;
        for (int i = 0; i < n - 1; i++)
            damage += min(mid, a[i + 1] - a[i]);

        if (damage >= h)
        {
            res = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }

    cout << res << '\n';
}
