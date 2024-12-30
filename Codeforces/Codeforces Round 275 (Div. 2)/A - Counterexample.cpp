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
ll GCD(ll a, ll b)
{
    if (b == 0) return a;
    return GCD(b, a % b);
}

void solve()
{
    ll l, r; cin >> l >> r;

    for (ll a = l; a <= r; a++)
        for (ll b = a + 1; b <= r; b++)
            for (ll c = b + 1; c <= r; c++)
                if (GCD(a, b) == 1 && GCD(b, c) == 1 && GCD(a, c) != 1)
                {
                    cout << a << ' ' << b << ' ' << c << '\n';
                    return;
                }
    cout << -1 << '\n';
}
