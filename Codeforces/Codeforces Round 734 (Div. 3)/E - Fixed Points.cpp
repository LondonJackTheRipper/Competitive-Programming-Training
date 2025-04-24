#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(n - k + 1, 0));
    dp[1][0] = (a[1] == 1);
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + (a[i] == i);
        for (int j = 1; j <= n - k; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
        if (a[i] < i && i - a[i] <= n - k)
            dp[i][i - a[i]] = max(dp[i][i - a[i]], dp[i - 1][i - a[i]] + 1);
    }

    int res = -1;
    for (int i = n - k; i >= 0; i--)
        if (dp[n][i] >= k)
            res = i;

    cout << res << '\n';
}
