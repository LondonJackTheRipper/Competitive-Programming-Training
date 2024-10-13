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

    if ((a + c) % 2 == 0 && ((a + c) / 2) % b == 0)
    {
        cout << "YES\n";
        return;
    }
    if (2 * b - c > 0 && (2 * b - c) % a == 0)
    {
        cout << "YES\n";
        return;
    }
    if (2 * b - a > 0 && (2 * b - a) % c == 0)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
