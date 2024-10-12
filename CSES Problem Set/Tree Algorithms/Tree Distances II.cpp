#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 9;
 
vector<int> adj[maxn];
int sz[maxn], h[maxn];
ll dp[maxn];
int n;
 
void dfs(int u, int p = -1)
{
	dp[1] += h[u];
	sz[u] = 1;
	
	for (int v : adj[u])
	{
		if (v == p) continue;
		
		h[v] = h[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
 
void dp_dfs(int u, int p)
{
	dp[u] = dp[p] - sz[u] + (n - sz[u]);
	
	for (int v : adj[u])
	{
		if (v == p) continue;
		
		dp_dfs(v, u);
	}
}
 
int main()
{
	faster();
 
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(1);
	for (int v : adj[1]) dp_dfs(v, 1);
	
	for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
 
	return 0;
}
