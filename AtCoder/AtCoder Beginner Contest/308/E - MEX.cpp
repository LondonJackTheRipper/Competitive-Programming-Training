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
const int maxn = 2e5 + 9;

int dp[maxn][3][8], arr[maxn];
string s, str = "MEX";
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cin >> s;

    for (int i = 1; i <= n; i++)
    {
        for (int last = 0; last < 3; last++)
            for (int mask = 0; mask < 8; mask++)
                dp[i][last][mask] = dp[i - 1][last][mask];

        if (s[i - 1] == 'M')
        {
            dp[i][0][1 << arr[i]]++;

            continue;
        }

        int pos = str.find(s[i - 1]);
        for (int mask = 0; mask < 8; mask++)
            dp[i][pos][mask | (1 << arr[i])] += dp[i - 1][pos - 1][mask];
    }

    int res = 0;
    for (int mask = 0; mask < 8; mask++)
    {
        if (dp[n][2][mask] == 0) continue;

        vector<int> cnt(4, 0);
        for (int i = 0; i < 3; i++)
            if (mask >> i & 1)
                cnt[i] = 1;

        int MEX = -1;
        for (int i = 0; i < 4; i++)
            if (cnt[i] == 0)
            {
                MEX = i;
                break;
            }

        res += MEX * dp[n][2][mask];
    }

    cout << res << '\n';
}
