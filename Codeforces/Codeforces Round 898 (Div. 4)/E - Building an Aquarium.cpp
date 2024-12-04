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
    int n, x; cin >> n >> x;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    int l = 1, r = 2e9, res = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        ll require = 0;
        for (int i = 1; i <= n; i++) require += max(0, mid - a[i]);

        if (require <= x)
        {
            res = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }

    cout << res << '\n';
}
