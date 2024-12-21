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
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    int l = 1, r = n;
    int mn = 1, mx = n;
    while (l < r)
    {
        if (a[l] == mx)
        {
            mx--;
            l++;
        } else
        if (a[l] == mn)
        {
            mn++;
            l++;
        } else
        if (a[r] == mx)
        {
            mx--;
            r--;
        } else
        if (a[r] == mn)
        {
            mn++;
            r--;
        } else
        {
            cout << l << ' ' << r << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}
