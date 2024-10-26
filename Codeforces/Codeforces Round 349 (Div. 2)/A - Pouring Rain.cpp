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
const long double pi = 3.1415926535;

void solve()
{
    int d, h, v, e; cin >> d >> h >> v >> e;

    long double s = pi * (d / 2.0) * (d / 2.0);

    if (e * s >= v)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << fixed << setprecision(4) << (h / ((v / s) - e)) << '\n';
}
