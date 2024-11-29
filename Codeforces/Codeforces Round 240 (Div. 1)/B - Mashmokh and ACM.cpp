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
const int mod = 1e9 + 7;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }

void solve()
{
    int n, k; cin >> n >> k;

    vector<int> state[n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if (j % i == 0)
                state[i].push_back(j);

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        dp[k][i] = 1;
    for (int i = k - 1; i > 0; i--)
        for (int j = 1; j <= n; j++)
            for (int x : state[j])
                dp[i][j] = add(dp[i][j], dp[i + 1][x]);

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = add(res, dp[1][i]);

    cout << res << '\n';
}
