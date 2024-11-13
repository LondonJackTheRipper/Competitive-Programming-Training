#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

const int maxn = 600;
int dp[2][maxn][maxn]; // dp[i][j][k]: ways of subset of the first i value sum of k can sum of j
int n, k;

void input()
{
	cin >> n >> k;
	
	dp[1][0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		int cur = i % 2;
		int pre = cur ^ 1;
		int x; cin >> x;
		
		for (int j = 0; j <= k; j++)
			for (int v = 0; v <= j; v++)
			{
				dp[cur][j][v] |= dp[pre][j][v];
				if (j >= x)
				{
					dp[cur][j][v] |= dp[pre][j - x][v];
					if (v >= x)
						dp[cur][j][v] |= dp[pre][j - x][v - x];
				}
			}
	}
	
	vector<int> res;
	for (int i = 0; i <= k; i++) if (dp[(n - 1) % 2][k][i])
		res.pb(i);
		
	cout << res.size() << '\n';
	for (int x : res) cout << x << ' ';
	cout << '\n';
}

int main()
{
// 	freopen("test.inp", "r", stdin);
// 	freopen("test.out", "w", stdout);
	faster();

	input();

	return 0;
}

