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

void solve()
{
    ll n, m; cin >> n >> m;

    ll div = (n + 1) / 2;
    cout << (m >= div ? 0ll : n - m * 2) << ' ';

    ll mx = 0;
    for (ll i = 2; i <= n; i++)
        if (i * (i - 1) / 2 <= m)
            mx = i;

    cout << n - (mx + (1ll * mx * (mx - 1) / 2 == m ? 0 : 1)) << '\n';
}
