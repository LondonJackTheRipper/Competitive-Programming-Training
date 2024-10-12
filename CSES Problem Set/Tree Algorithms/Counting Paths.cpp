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
int par[maxn][20], h[maxn];
int res[maxn];
int n, m;
 
void dfs(int u)
{	
	for (int v : adj[u])
	{
		if (v == par[u][0]) continue;
		
		h[v] = h[u] + 1;
		par[v][0] = u;
		for (int i = 1; i < 20; i++)
			par[v][i] = par[par[v][i - 1]][i - 1];
			
		dfs(v);
	}
}
 
void dfs_res(int u)
{
	for (int v : adj[u])
	{
		if (v == par[u][0]) continue;
		
		dfs_res(v);
		res[u] += res[v];
	}
}
 
int lca(int u, int v)
{
	if (h[u] > h[v]) swap(u, v);
	int k = h[v] - h[u];
	
	for (int i = 0; i < 20; i++)
		if ((k >> i) & 1)
			v = par[v][i];
			
	
	if (u == v) return u;
 
	for (int i = 19; i >= 0; i--)
		if (par[u][i] != par[v][i])
		{
			u = par[u][i];
			v = par[v][i];
		}
		
	return par[u][0];
}
 
int main()
{
	faster();
 
	cin >> n >> m;
	
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(1);
	
	while (m--)
	{
		int a, b; 
		cin >> a >> b;
 
		int LCA = lca(a, b); 
		res[a]++;
		res[b]++;
		res[LCA]--;
		if (LCA != 1) res[par[LCA][0]]--;
	}
	
	dfs_res(1);
	
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
 
	return 0;
}
