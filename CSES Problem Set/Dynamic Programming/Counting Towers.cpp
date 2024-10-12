#include <bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back
 
const int maxn = 1e6 + 9;
const ll mod = 1e9 + 7;
 
vector<vector<ll>> dp(maxn, vector<ll>(3, 0));
 
void init()
{
	dp[1][1] = dp[1][2] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		dp[i][1] = (4 * dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][2] = (dp[i - 1][1] + 2 * dp[i - 1][2]) % mod; 
	}
}
 
void input()
{
	int n; cin >> n;
	
	cout << (dp[n][1] + dp[n][2]) % mod << '\n';
}
 
int main()
{
	faster();
 
	init();
	int t; cin >> t;
	while (t--) input();
 
	return 0;
}
