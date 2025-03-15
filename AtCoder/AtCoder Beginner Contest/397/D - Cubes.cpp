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
bool can(ll d, ll k, ll n)
{
    n -= d * d * d;
    if (n % (3 * d) != 0) return false;
    n /= (3 * d);
    if (n % k != 0) return false;
    n /= k;
    return (n == (d + k));
}

void solve()
{
    ll n; cin >> n;

    for (ll d = 1; d * d * d <= n; d++)
    {
        ll l = 1, r = 1e9;
        while (l <= r)
        {
            ll mid = l + r >> 1;

            if (can(d, mid, n))
            {
                cout << d + mid << ' ' << mid << '\n';
                return;
            } else
            if (d + mid <= (n - d * d * d) / (3 * d * mid))
                l = mid + 1;
            else
                r = mid - 1;
        }
    }

    cout << -1 << '\n';
}
