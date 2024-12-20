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

    if ((a + b + c) % 9 != 0)
    {
        cout << "NO\n";
        return;
    }

    int div = (a + b + c) / 9;
    if (div > min({a, b, c}))
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}
