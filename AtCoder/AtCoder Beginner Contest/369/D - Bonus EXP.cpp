#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 2e5 + 9;

int n;
ll arr[maxn];
ll dp[2][maxn];
// 0: even
// 1: odd

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	dp[0][1] = 0;
	dp[1][1] = arr[1];
	ll mxeven = 0, mxodd = arr[1];
	for (int i = 2; i <= n; i++)
	{
		dp[0][i] = mxodd + 2 * arr[i];
		dp[1][i] = mxeven + arr[i];
		mxodd = max(mxodd, dp[1][i]);
		mxeven = max(mxeven, dp[0][i]);
	}

	cout << max(mxeven, mxodd) << '\n';

	return 0;
}
