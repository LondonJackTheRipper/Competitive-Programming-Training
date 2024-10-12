#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int inf = 1e9 + 9;
const int maxn = 5009;
string a, b;
 
void input()
{
	cin >> a >> b;
	
	int n = a.length(), m = b.length();
	vector<vector<int>> dp(maxn, vector<int>(maxn, 0));
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
		{
			if (i == 0)
			{
				dp[i][j] = j;
				continue;
			}
			if (j == 0)
			{
				dp[i][j] = i;
				continue;
			}
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else 
				dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
		}
		
	cout << dp[n][m] << '\n';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	
	input();
 
	return 0;
}
