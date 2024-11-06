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
    ll x; cin >> x;

    for (ll i = 1; i * i * i <= x; i++)
    {
        ll cubes = ceil(pow(x - i * i * i, 1.0/3.0));
        if (cubes == 0) continue;

        if (cubes * cubes * cubes == x - i * i * i)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
