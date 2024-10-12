#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const ll mod = 1e9 + 7;
int n, SUM;
 
void input()
{
	cin >> n;
	
	SUM = (n + 1) * n / 2;
	if (SUM % 2)
	{
		cout << 0 << '\n';
		return;
	}
	SUM /= 2;
	vector<ll> dp(SUM + 1, 0);
	dp[0] = 1;
	
	for (int i = 2; i <= n; i++) 
		for (int j = SUM; j >= i; j--)
			dp[j] = (dp[j] + dp[j - i]) % mod;
			
	cout << dp[SUM] << '\n';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
