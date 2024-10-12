#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 21;
int arr[maxn];
int n, x;
 
void input()
{
	cin >> n >> x;
	
	vector<pair<int, int>> dp(1 << maxn, {n + 1, x + 1});
	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0] = {1, 0};
	
	for (int mask = 0; mask < (1 << n); mask++)
		for (int i = 0; i < n; i++)
			if (mask & (1 << i))
			{
				int pre = mask ^ (1 << i);
				auto it = dp[pre];
				int num = it.first;
				int weight = it.second;
				
				if (weight + arr[i] <= x)
					weight += arr[i];
				else
				{
					weight = arr[i];
					num++;
				}
				dp[mask] = min(dp[mask], make_pair(num, weight));
			}
			
	cout << dp[(1 << n) - 1].first << '\n';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
