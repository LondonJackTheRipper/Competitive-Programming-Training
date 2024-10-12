#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int mod = 1e9 + 7;
int dp[1000009];
int n;
 
void input()
{
	cin >> n;
	
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 6; j++)
		{
			if (i >= j) dp[i] = (dp[i] + dp[i - j]) % mod;
		}
		
	cout << dp[n] << '\n';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
