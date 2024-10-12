#include <bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ll long long
#define pb push_back
 
const int oo = 1e9 + 7;
 
void input()
{
	int a, b; cin >> a >> b;
	vector<vector<int>> dp(a + 1, vector<int>(b + 1, oo));
	
	for (int i = 0; i <= a; i++)
		for (int j = 0; j <= b; j++)
		{
			if (i == j)
			{
				dp[i][j] = 0;
				continue;
			}
			for (int ii = 0; ii < i; ii++)
				dp[i][j] = min(dp[i][j], dp[ii][j] + dp[i - ii][j] + 1);
			for (int jj = 0; jj < j; jj++)
				dp[i][j] = min(dp[i][j], dp[i][jj] + dp[i][j - jj] + 1);
		}
		
	cout << dp[a][b] << '\n'; 
}
 
int main()
{
	faster();
 
	input();
 
	return 0;
}
