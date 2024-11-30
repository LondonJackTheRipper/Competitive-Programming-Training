#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

void input()
{
	int n; cin >> n;
	vector<int> a(n + 1);
	int total = 0;
	
	for (int i = 1; i <= n; i++) cin >> a[i], total += a[i];
	
	if (total & 1)
	{
		cout << "NO\n";
		return;
	}
	total /= 2;
	vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));
	for (int i = 1; i <= n; i++) dp[i][0] = 1;
	
	for (int i = 1; i <= n; i++)
		for (int j = total; j >= 1; j--)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]]);
		}
		
	cout << (dp[n][total] == 1 ? "YES\n" : "NO\n");
}

int main()
{
   faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
