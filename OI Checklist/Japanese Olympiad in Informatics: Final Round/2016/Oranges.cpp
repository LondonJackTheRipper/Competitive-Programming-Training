#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const ll oo = 1e18;
const int maxn = 2e4 + 9;
const int segsize = 4 * maxn;

int n, m, k;
ll arr[maxn];

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	vector<ll> dp(n + 1, oo);
	dp[0] = 0;
	
	for (int i = 1; i <= n; i++)
	{
		ll mn = oo, mx = -oo;
		for (int j = i; j >= max(1, i - m + 1); j--)
		{
			mn = min(mn, arr[j]);
			mx = max(mx, arr[j]);
			dp[i] = min(dp[i], dp[j - 1] + k + (i - j + 1) * (mx - mn));
		}
	}
	
	cout << dp[n] << '\n';

	return 0;
}
