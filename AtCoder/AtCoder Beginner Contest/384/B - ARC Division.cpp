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
    int n, r; cin >> n >> r;

    while (n--)
    {
        int d, a; cin >> d >> a;

        if ((d == 1 && 1600 <= r && r <= 2799) || (d == 2 && 1200 <= r && r <= 2399))
            r += a;
    }

    cout << r << '\n';
}
