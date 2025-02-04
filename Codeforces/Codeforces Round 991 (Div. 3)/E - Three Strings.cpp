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
const int oo = 1e9;

void solve()
{
    string a, b, c; cin >> a >> b >> c;
    int n = (int)a.length(), m = (int)b.length();

    vector<vector<int>> dp(n + m, vector<int>(n + 1, oo));
    // dp[i][j]: up to index i in c, using j characters in a
    dp[0][0] = (c[0] != b[0]);
    dp[0][1] = (c[0] != a[0]);
    for (int i = 1; i < n + m; i++)
    {
        for (int j = 0; j <= min(n, i + 1); j++)
        {
            if (j != 0)
                dp[i][j] = dp[i - 1][j - 1] + (c[i] != a[j - 1]);
            if (i - j < m)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + (c[i] != b[i - j]));
        }
    }

    cout << dp[n + m - 1][n] << '\n';
}
