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
const int mod = 998244353;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[i - 1])
            dp[i] = add(dp[i], dp[i - 1]);
        if (i >= 2 && a[i] == a[i - 2] + 1)
            dp[i] = add(dp[i], dp[i - 2]);
    }

    cout << add(dp[n], dp[n - 1]) << '\n';
}
