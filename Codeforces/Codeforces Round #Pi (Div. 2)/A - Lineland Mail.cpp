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
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        cout << min(i == 0 ? 2000000000 : a[i] - a[i - 1], i == n - 1 ? 2000000000 : a[i + 1] - a[i]);
        cout << ' ';
        cout << max(i == 0 ? -2000000000 : a[i] - a[0], i == n - 1 ? -2000000000 : a[n - 1] - a[i]);
        cout << '\n';
    }
}
