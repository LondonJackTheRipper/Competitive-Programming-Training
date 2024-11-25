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
    ll n; cin >> n;

    ll used = (n + 5) / 6;
    ll res = used * 15;
    ll rem = n % 6;
    if ((rem == 3 || rem == 4) && used >= 2)
        res = 1ll * (used - 2) * 15 + 25;
    else
    if ((rem == 1 || rem == 2) && used >= 2)
        res = 1ll * (used - 2) * 15 + 20;

    cout << res << '\n';
}
