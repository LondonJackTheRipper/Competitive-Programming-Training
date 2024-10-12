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

    int res = 2e9;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
            if (mask >> i & 1)
                sum1 += a[i];
            else
                sum2 += a[i];
        res = min(res, max(sum1, sum2));
    }
    cout << res << '\n';
}

