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
ll compute(ll st, ll n)
{
    ll k = (n - st) / 4;
    return (k + 1) * st + 4 * k * (k + 1) / 2;
}

void solve()
{
    ll x, n; cin >> x >> n;

    ll res = 0;
    for (ll i = 1; i <= min(n, 5ll); i++)
    {
        if (i == 1)
            res += (x % 2 == 0 ? -1 : 1); else
        if (i == 2 || i == 3)
            res += (x % 2 == 0 ? compute(i, n) : -compute(i, n));
        else
            res += (x % 2 == 0 ? -compute(i, n) : compute(i, n));
    }

    cout << x + res << '\n';
}
