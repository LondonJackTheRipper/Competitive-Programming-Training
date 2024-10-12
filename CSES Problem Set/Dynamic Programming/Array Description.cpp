#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 9;
int arr[maxn];
int n, m;
 
void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	vector<vector<ll>> dp(maxn, vector<ll>(109, 0));
	
	for (int i = 0; i < n; i++)
		if (arr[i] != 0)
		{
			if (i == 0)
				dp[i][arr[i]] = 1;
			else 
				dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] - 1] + dp[i - 1][arr[i]] + dp[i - 1][arr[i] + 1]) % mod;
 		} else 
 		{
 			for (int j = m; j >= 1; j--)
 			{
 				if (i == 0) dp[i][j] = 1; else
				 	dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;	
			}
		}
		
	ll ans = 0;
	for (int i = 1; i <= m; i++)
		ans = (ans + dp[n - 1][i]) % mod;
		
	cout << ans << '\n';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
