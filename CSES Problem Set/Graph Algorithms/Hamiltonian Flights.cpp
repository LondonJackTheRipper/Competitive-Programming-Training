#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 21;
const ll mod = 1e9 + 7;
 
vector<int> rev[maxn];
ll dp[1 << maxn][maxn];
int n, m;
 
void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		rev[--y].pb(--x);
	}
	
	dp[1][0] = 1;
	for (int s = 2; s < (1 << n); s++)
	{
		if ((s & 1) == 0) continue;
		if (s & (1 << (n - 1)) && s != ((1 << n) - 1)) continue;
		
		for (int end = 0; end < n; end++)
		{
			if ((s & (1 << end)) == 0) continue;
			
			int pre = s - (1 << end);
			for (int v : rev[end])
			{
				if ((s & (1 << v)) == 0) continue;
				dp[s][end] += dp[pre][v];
				dp[s][end] %= mod;
			}
		}
	}
	
	cout << dp[(1 << n) - 1][n - 1];
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
