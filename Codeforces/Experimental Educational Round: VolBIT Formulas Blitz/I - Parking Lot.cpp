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

ll power(ll a, int b)
{
    if (b < 0) return 0;
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

void solve()
{
    int n; cin >> n;

    cout << 2ll * 4 * 3 * power(4, n - 3) + 1ll * (n - 3) * 4 * 3 * 3 * power(4, n - 4) << '\n';
}
