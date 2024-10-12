#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 9;
vector<int> adj[maxn];
int dp[maxn][2];
int n;
 
void dfs(int u, int p = -1)
{
	for (int v : adj[u])
		if (v != p)
			dfs(v, u), dp[u][0] += max(dp[v][0], dp[v][1]);
	for (int v : adj[u])
		if (v != p)
			dp[u][1] = max(dp[u][1], dp[v][0] + 1 + dp[u][0] - max(dp[v][0], dp[v][1]));
}
 
void input()
{
	cin >> n;
	
	for (int i = 1; i < n; i++)
	{
		int x, y; cin >> x >> y;
		adj[--x].pb(--y);
		adj[y].pb(x);
	}
	dfs(0);
	
	cout << max(dp[0][0], dp[0][1]) << '\n';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
