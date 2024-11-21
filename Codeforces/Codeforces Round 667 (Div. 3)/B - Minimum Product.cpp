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
    int a, b, x, y, n; cin >> a >> b >> x >> y >> n;

    int tmp = n;
    int res1 = min(a - x, tmp);
    tmp -= res1;
    int res2 = min(b - y, tmp);

    ll ans = 1ll * (a - res1) * (b - res2);

    res1 = min(b - y, n);
    n -= res1;
    res2 = min(a - x, n);

    cout << min(ans, 1ll * (b - res1) * (a - res2)) << '\n';
}
