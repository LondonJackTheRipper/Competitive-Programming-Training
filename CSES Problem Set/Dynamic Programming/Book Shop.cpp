#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 1e3 + 9;
int dp[maxn][100009];
int h[maxn], s[maxn];
int n, x;
 
void input()
{
	cin >> n >> x;
	
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> s[i];
	
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= x; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= h[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + s[i]);
		}
		
	cout << dp[n][x] << '\n';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
