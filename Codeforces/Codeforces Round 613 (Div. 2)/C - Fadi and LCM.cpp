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
ll GCD(ll a, ll b) { return (b == 0 ? a : GCD(b, a % b)); }
ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }

void solve()
{
    ll x; cin >> x;

    ll a, b, res = 1e18;
    for (int i = 1; 1ll * i * i <= x; i++)
    {
        if (x % i != 0) continue;

        ll u = i, v = x / i;
        if (LCM(u, v) == x && max(u, v) < res)
        {
            res = max(u, v);
            a = u;
            b = v;
        }
    }

    cout << a << ' ' << b << '\n';
}
