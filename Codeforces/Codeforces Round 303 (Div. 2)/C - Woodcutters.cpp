#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

const int maxn = 1e5 + 9;

/* 3 states
0: remain
1: to the left
2: to the right
*/

ll x[maxn], h[maxn];
int dp[maxn][3];
int n;

int main()
{
   faster();

	cin >> n;
	
	for (int i = 1; i <= n; i++) cin >> x[i] >> h[i];
	x[0] = -1e9; h[0] = 0;
	
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		// remain
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		if (x[i - 1] + h[i - 1] < x[i]) 
			dp[i][0] = max(dp[i][0], dp[i - 1][2]);
			
		// to the left
		if (x[i] - h[i] > x[i - 1])
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
		if (x[i] - h[i] > x[i - 1] + h[i - 1])
			dp[i][1] = max(dp[i][1], dp[i - 1][2] + 1);
		
		// to the right
		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
		if (x[i - 1] + h[i - 1] < x[i])
			dp[i][2] = max(dp[i][2], dp[i - 1][2] + 1);
			
		// update res
		res = max({res, dp[i][0], dp[i][1], dp[i][2]});
	}
	
	cout << res << '\n';

	return 0;
}
