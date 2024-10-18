#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

const int maxn = 2e5 + 9;

vector<int> adj[maxn];
int deg[maxn], vis[maxn];
int n, m;
bool ok = true;

void dfs(int u)
{
	if (deg[u] != 2) ok = false;
	vis[u] = 1;
	
	for (int v : adj[u])
	{
		if (vis[v] == 1) continue;
		
		dfs(v);
	}
}

int main()
{
   faster();

	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		deg[u]++;
		deg[v]++;
	}
	
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (vis[i] == 0)
		{
			ok = true;
			dfs(i);
			res += ok;
		}
		
	cout << res << '\n';

	return 0;
}
