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
const int oo = 1e9;

void solve()
{
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(3, oo));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
            dp[i][0] = min(dp[i][0], dp[i - 1][j] + 1);
        if (a[i] == 1)
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        else
        if (a[i] == 2)
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        else
        if (a[i] == 3)
        {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
    }

    int res = oo;
    if (a[n] == 3)
        res =  min(dp[n][1], dp[n][2]);
    else
        res = dp[n][a[n]];

    cout << res << '\n';
}
