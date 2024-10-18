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

int mah(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve()
{
    int xa, ya; cin >> xa >> ya;
    int xb, yb; cin >> xb >> yb;
    int xc, yc; cin >> xc >> yc;

    int ab = mah(xa, ya, xb, yb) + 1;
    int ac = mah(xa, ya, xc, yc) + 1;
    int bc = mah(xb, yb, xc, yc) + 1;

    if (bc == ab + ac)
        cout << 1 << '\n';
    else
    if (ab + bc == ac || ac + bc == ab)
        cout << min(ab, ac) << '\n';
    else
        cout << (ab + ac - bc + 1) / 2 << '\n';
}
