#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const ll mod = 1e9 + 7;
vector<ll> dp(10000000, 0);
int arr[200];
int n, x;
 
void input()
{
	cin >> n >> x;
	dp[0] = 1;
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	for (int i = 0; i <= x; i++)
		for (int j = 0; j < n; j++)
			if (i >= arr[j])
				dp[i] = (dp[i] + dp[i - arr[j]]) % mod;
				
	cout << dp[x] << '\n';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
