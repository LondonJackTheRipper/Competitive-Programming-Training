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
    int h[n][2];
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= n; j++)
            cin >> h[j][i];

    vector<vector<ll>> dp(n + 1, vector<ll>(3, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][0] = max(dp[i][0], dp[i - 1][j]);
            if (j != 1)
                dp[i][1] = max(dp[i][1], dp[i - 1][j] + h[i][0]);
            if (j != 2)
                dp[i][2] = max(dp[i][2], dp[i - 1][j] + h[i][1]);
        }
    }

    ll res = 0;
    for (int i = 0; i < 3; i++)
        res = max(res, dp[n][i]);

    cout << res << '\n';
}
