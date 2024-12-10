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
    int a, b, c; cin >> a >> b >> c;
    int k = (c % a == 0 ? c / a - 1 : c / a);

    if (c < 1ll * b * a)
        cout << (k > 0 ? k : -1) << ' ' << b << '\n';
    else
    if (c > 1ll * b * a)
        cout << b << ' ' << -1 << '\n';
    else
        cout << 1 << ' ' << -1 << '\n';
}
