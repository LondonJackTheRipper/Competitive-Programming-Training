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
int res[maxn];
int n;
 
// max nodes;
int hh[maxn];
int node;
void dfs_max(int u, int p = -1)
{
	if (hh[u] > hh[node]) node = u;
	
	for (int v : adj[u])
	{
		if (v == p) continue;
		
		hh[v] = hh[u] + 1;
		dfs_max(v, u);
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
	
	dfs_max(1);
	for (int i = 1; i <= n; i++) hh[i] = 0;
	dfs_max(node);
	for (int i = 1; i <= n; i++)
		res[i] = max(res[i], hh[i]);
	for (int i = 1; i <= n; i++) hh[i] = 0;
	dfs_max(node);
	for (int i = 1; i <= n; i++)
		res[i] = max(res[i], hh[i]);
		
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
 
	return 0;
}
