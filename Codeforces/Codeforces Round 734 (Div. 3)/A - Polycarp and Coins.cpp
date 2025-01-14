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
    int n; cin >> n;

    int c2 = n * 2 / 3 / 2;
    int c1 = n - 2 * c2;
    if (c1 > 1 && abs(c1 - c2) > abs(c1 - 2 - (c2 + 1)))
    {
        c1 -= 2;
        c2++;
    }

    cout << c1 << ' ' << c2 << '\n';
}
