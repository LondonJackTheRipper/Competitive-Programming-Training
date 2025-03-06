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
    int a, b; cin >> a >> b;

    cout << 5 << '\n';
    if (5 * a > b)
    {
        if (b >= 0)
            cout << -2 * b - 1 << ' ' << 0 << ' ' << b << ' ' << b + 1 << ' ' << 5 * a << '\n';
        else
            cout << b - 1 << ' ' << b - 1 << ' ' << b << ' ' << -3 * b + 2 << ' ' << 5 * a << '\n';
    } else
    {
        if (b >= 0)
            cout << -3 * b - 2 << ' ' << 5 * a << ' ' << b << ' ' << b + 1 << ' ' << b + 1 << '\n';
        else
            cout << b - 1 << ' ' << 5 * a << ' ' << b << ' ' << 0 << ' ' << -2 * b + 1 << '\n';
    }
}
