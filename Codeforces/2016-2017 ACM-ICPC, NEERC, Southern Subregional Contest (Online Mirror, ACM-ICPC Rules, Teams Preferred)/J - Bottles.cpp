#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
    int SumOfRem = 0, SumOfCap = 0;
    vector<pair<int, int>> v(n);
    for (pair<int, int>& it : v) cin >> it.second, SumOfRem += it.second;
    for (pair<int, int>& it : v) cin >> it.first, SumOfCap += it.first;

    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int cur = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        cur += v[i].first;

        if (cur - SumOfRem >= 0)
        {
            k = i + 1;
            break;
        }
    }

    int dp[k + 1][SumOfCap + 1];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = k; j > 0; j--)
            for (int u = SumOfCap; u >= v[i - 1].first; u--)
                if (dp[j - 1][u - v[i - 1].first] != -1)
                    dp[j][u] = max(dp[j][u], dp[j - 1][u - v[i - 1].first] + v[i - 1].second);

    int t = 0;
    for (int i = SumOfRem; i <= SumOfCap; i++)
        t = max(t, dp[k][i]);
    t = SumOfRem - t;

    cout << k << ' ' << t << '\n';
}
