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

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// main program

void solve()
{
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<int> dp(n + 1, 0), last(n + 1, 1e9);
    dp[1] = 1;
    last[a[1]] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        
        if (last[a[i]] != (int)1e9)
            dp[i] = min(dp[i], last[a[i]]);
            
        last[a[i]] = min(last[a[i]], dp[i]);
    }
    
    cout << dp[n] << '\n';
}
