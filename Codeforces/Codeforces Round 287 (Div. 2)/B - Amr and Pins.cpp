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
    ll r, x, y, xx, yy;
    cin >> r >> x >> y >> xx >> yy;

    ll dist = (x - xx) * (x - xx) + (y - yy) * (y - yy);
    r = (2 * r) * (2 * r);

    cout << ceil(sqrt((dist + r - 1) / r)) << '\n';
}
