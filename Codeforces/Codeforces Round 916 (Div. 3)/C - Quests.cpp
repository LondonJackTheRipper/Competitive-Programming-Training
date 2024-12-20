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
    int n, k; cin >> n >> k;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    int res = 0;
    int prefix = 0, mx = 0;
    for (int i = 1; i <= min(n, k); i++)
    {
        prefix += a[i];
        mx = max(mx, b[i]);
        int rem = k - i;

        res = max(res, prefix + rem * mx);
    }

    cout << res << '\n';
}
