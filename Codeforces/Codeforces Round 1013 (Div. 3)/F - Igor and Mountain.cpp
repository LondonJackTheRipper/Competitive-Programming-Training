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
const int mod = 998244353;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int sub(int a, int b) { a -= b; if (a < 0) a += mod; return a; }
int mul(int a, int b) { return 1ll * a * b % mod; }

int n, m, d;

void solve()
{
    cin >> n >> m >> d;
    int dist_hor, dist_diag;
    for (int i = m; i >= 0; i--)
    {
        if ((m - i) * (m - i) <= d * d)
            dist_hor = m - i;
        if ((m - i) * (m - i) <= d * d - 1)
            dist_diag = m - i;
    }
    char c[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];

    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(m + 1)));
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; i++)
        prefix[1][i] = prefix[1][i - 1] + (dp[0][1][i] = (c[1][i] == 'X'));
    for (int i = 1; i <= m; i++)
        if (c[1][i] == 'X')
            dp[1][1][i] = prefix[1][min(m, i + dist_hor)] - prefix[1][max(1, i - dist_hor) - 1] - 1;
    for (int i = 1; i <= m; i++)
        prefix[1][i] = prefix[1][i - 1] + dp[0][1][i] + dp[1][1][i];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] != 'X') continue;
            int l = max(1, j - dist_diag), r = min(m, j + dist_diag);
            dp[0][i][j] = sub(prefix[i - 1][r], prefix[i - 1][l - 1]);
        }
        for (int j = 1; j <= m; j++)
            prefix[i][j] = add(prefix[i][j - 1], dp[0][i][j]);
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] != 'X') continue;
            int l = max(1, j - dist_hor), r = min(m, j + dist_hor);
            dp[1][i][j] = sub(sub(prefix[i][r], prefix[i][l - 1]), dp[0][i][j]);
        }
        for (int j = 1; j <= m; j++)
            prefix[i][j] = add(prefix[i][j - 1], add(dp[0][i][j], dp[1][i][j]));
    }

    cout << prefix[n][m] << '\n';
}
