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

    solve();

    return 0;
}

// main program
const int mx = 1e5;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 9;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int sub(int a, int b) { a -= b; if (a < 0) a += mod; return a; }

int t, k;
int dp[maxn];

void solve()
{
    cin >> t >> k;

    for (int i = 0; i < min(k, mx); i++)
        dp[i] = 1;
    for (int i = min(k, mx); i <= mx; i++)
        dp[i] = add(dp[i - 1], dp[i - k]);
    for (int i = 1; i <= mx; i++)
        dp[i] = add(dp[i - 1], dp[i]);

    while (t--)
    {
        int a, b; cin >> a >> b;

        cout << sub(dp[b], dp[a - 1]) << '\n';
    }
}
