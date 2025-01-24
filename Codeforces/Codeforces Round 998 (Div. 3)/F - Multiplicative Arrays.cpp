#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

string name = "test";

void solve(vector<pair<int, int>>& Test);
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    vector<pair<int, int>> Test(t);
    for (auto &it : Test)
        cin >> it.first >> it.second;

    solve(Test);

    return 0;
}

// main program
const int mod = 998244353;
const int maxbit = 16;
const int maxk = 1e5;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int mul(int a, int b) { return 1ll * a * b % mod; }

int power(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = mul(ans, a);
        a = mul(a, a);
        b /= 2;
    }
    return ans;
}

void solve(vector<pair<int, int>>& Test)
{
    vector<int> divs[maxk + 1];
    for (int i = 2; i <= maxk; i++)
        for (int j = 2 * i; j <= maxk; j += i)
            divs[j].push_back(i);
    vector<vector<int>> dp(maxk + 1, vector<int>(maxbit + 1, 0));
    for (int i = 2; i <= maxk; i++)
        dp[i][1] = 1;
    for (int j = 2; j <= maxbit; j++)
        for (int i = 2; i <= maxk; i++)
            for (int div : divs[i])
                dp[i][j] = add(dp[i][j], dp[i / div][j - 1]);

    for (pair<int, int> it : Test)
    {
        int k = it.first, n = it.second;

        cout << n << ' ';
        for (int kk = 2; kk <= k; kk++)
        {
            int ans = 0;

            vector<int> Precompute(maxbit + 1, 1);
            for (int j = 0; j <= maxbit; j++)
            {
                if (n - j + 1 < 1)
                {
                    Precompute[j] = 0;
                    continue;
                }
                Precompute[j] = mul(Precompute[j], n - j + 1);
                Precompute[j] = mul(Precompute[j], power(j + 1, mod - 2));
            }
            for (int j = 1; j <= maxbit; j++)
            {
                int res = dp[kk][j];
                for (int i = 0; i <= j; i++)
                    res = mul(res, Precompute[i]);

                ans = add(ans, res);
            }

            cout << ans << ' ';
        }
        cout << '\n';
    }
}
