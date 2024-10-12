#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int mod = 1e9 + 7;
const int maxn = 1e7;
vector<int> dp(maxn, 0);
int arr[200];
int n, x;
 
void input()
{
	cin >> n >> x;
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0] =1;
	
	for (int i = 0; i < n; i++)
		for (int j = arr[i]; j <= x; j++)
			dp[j] = (dp[j] + dp[j - arr[i]]) % mod;
			
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
