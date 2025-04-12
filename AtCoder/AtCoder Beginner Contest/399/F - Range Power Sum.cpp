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
const int mod = 998244353;
const int maxn = 2e5 + 1;
const int maxk = 11;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int sub(int a, int b) { a -= b; if (a < 0) a += mod; return a; }
int mul(int a, int b) { return 1ll * a * b % mod; }

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b % 2 == 1)
            res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

int C[maxk][maxk];
void comb(int n)
{
    for (int i = 0; i <= n; i++)
    {
        C[i][i] = C[0][i] = 1;
        for (int j = 1; j < i; j++)
            C[j][i] = add(C[j][i - 1], C[j - 1][i - 1]);
    }
}

int a[maxn];
int dp[11][maxn], save[11][maxn];

void solve()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    comb(10);

    for (int i = 0; i <= k; i++)
        dp[i][1] = power(a[1], i);
    int pre = a[1], total = a[1];
    for (int i = 2; i <= n; i++)
    {
        pre = add(pre, a[i]);
        total = add(total, pre);

        dp[0][i] = i;
        for (int j = 1; j <= k; j++)
        {
            dp[j][i] = dp[j][i - 1];
            for (int l = 1; l <= j; l++)
                dp[j][i] = add(dp[j][i], mul(dp[j - l][i - 1], mul(C[l][j], power(a[i], l))));
            dp[j][i] = add(dp[j][i], power(a[i], j));
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = add(res, dp[k][i]);
    cout << res << '\n';
}
