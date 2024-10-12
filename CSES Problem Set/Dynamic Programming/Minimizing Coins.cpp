#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int inf = 1e9 + 7;
const int maxn = 1e8 + 9;
vector<int> dp(maxn, inf);
int n, x;
 
void input()
{
	cin >> n >> x;
	
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		for (int i = num; i <= x; i++)
			dp[i] = min(dp[i], dp[i - num] + 1);
	}
	
	cout << (dp[x] == inf ? -1 : dp[x]) << '\n'; 
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
