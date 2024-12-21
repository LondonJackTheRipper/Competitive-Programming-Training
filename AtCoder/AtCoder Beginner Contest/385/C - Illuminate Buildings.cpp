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
    int h[n + 1];
    for (int i = 1; i <= n; i++) cin >> h[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            dp[i][j] = 1;
        for (int j = i - 1; j > 0; j--)
        {
            if (h[i] != h[j]) continue;

            int diff = i - j;
            dp[i][diff] = dp[j][diff] + 1;
            res = max(res, dp[i][diff]);
        }
    }

    cout << res << '\n';
}
