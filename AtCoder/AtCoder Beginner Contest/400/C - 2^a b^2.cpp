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
ll compute(ll k, ll n)
{
    ll l = 1, r = 1e9;
    ll res = 0;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        if (mid * mid * k <= n)
        {
            l = mid + 1;
            res = mid;
        } else
            r = mid - 1;
    }

    return res;
}

void solve()
{
    ll n; cin >> n;

    cout << compute(2, n) + compute(4, n) << '\n';
}
