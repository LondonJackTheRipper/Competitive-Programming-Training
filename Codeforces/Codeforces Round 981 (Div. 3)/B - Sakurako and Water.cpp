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
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        int mn = 1e9;
        for (int j = 0; j < n - i; j++)
            mn = min(mn, a[j][i + j]);
        res -= min(mn, 0);
    }
    for (int i = 1; i < n; i++)
    {
        int mn = 1e9;
        for (int j = 0; j < n - i; j++)
            mn = min(mn, a[i + j][j]);
        res -= min(mn, 0);
    }

    cout << res << '\n';
}