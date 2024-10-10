#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

const ll inf = 1e18 + 9;
const int maxn = 5e4 + 9;
int c[60], h[60];
ll dp[maxn]; // dp[i]: minimum cost to achieve hapiness of i
int m, x;

void input()
{
	cin >> m >> x;
	
	int mh = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> c[i] >> h[i];
		mh += h[i];
	}
	for (int i = 0; i <= mh; i++)
		dp[i] = inf;
	dp[0] = 0;
		
	for (int i = 0; i < m; i++)
		for (int j = mh; j >= h[i]; j--)
			if (dp[j - h[i]] + c[i] <= 1ll * i * x)
				dp[j] = min(dp[j], dp[j - h[i]] + c[i]);
			
	for (int i = mh; i >= 0; i--) if (dp[i] != inf)
	{
		cout << i << '\n';
		break;
	}
}

int main()
{
// 	freopen("test.inp", "r", stdin);
// 	freopen("test.out", "w", stdout);
	faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
