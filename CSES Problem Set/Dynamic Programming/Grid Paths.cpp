#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int mod = 1e9 + 7;
const int maxn = 1009;
int dp[maxn][maxn];
char a[maxn][maxn];
int n; 
 
void input()
{
	cin >> n;
	
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
			
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (a[i][j] != '*')
		{
			if (i - 1 >= 1 && a[i - 1][j] != '*') dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
			if (j - 1 >= 1 && a[i][j - 1] != '*') dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
		} else dp[i][j] = 0;
		
	cout << dp[n][n] << '\n';
			
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();	
 
	return 0;
}
