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

    if (n == 1)
    {
        cout << -1 << '\n';
        return;
    }

    if ((3 * n - 1) % 3 != 0)
    {
        cout << 2;
        for (int i = 0; i < n - 1; i++) cout << 3; cout << '\n';
    } else
    if ((2 * n + 1) % 3 != 0)
    {
        for (int i = 0; i < n - 1; i++) cout << 2;
        cout << 3 << '\n';
    } else
        cout << -1 << '\n';
}
