#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98
  
  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 5e5 + 9;

vector<int> adj[maxn], depth[maxn];
int h[maxn], par[20][maxn];
int n, mx_h = 0;

void DFS(int u, int hh = 0, int p = -1)
{
	depth[hh].push_back(u);
	mx_h = max(mx_h, hh);
	for (int v : adj[u])
	{
		if (v == p) continue;
		
		h[v] = h[u] + 1;
		par[0][v] = u;
		for (int i = 1; i < 20; i++)
			par[i][v] = par[i - 1][par[i -1][v]];
		
		DFS(v, hh + 1, u);
	}
}

int LCA(int u, int v)
{
	if (h[u] < h[v]) swap(u, v);
	int k = h[u] - h[v];
	
	for (int i = 0; i < 20; i++)
		if (k >> i & 1)
			u = par[i][u];
			
	if (u == v) return u;
	
	for (int i = 19; i >= 0; i--)
		if (par[i][u] != par[i][v])
		{
			u = par[i][u];
			v = par[i][v];
		} 
		
	return par[0][u];
}

void input()
{
	cin >> n;
	for (int i = 0; i<= n ; i++)
	{
		adj[i].clear(); depth[i].clear();
		h[i] = 0;
		mx_h = 0;
		for (int j = 0; j < 20; j++)
			par[j][i] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	DFS(1);
	
	int ans = 1e9;
	
	for (int i = 1; i <= mx_h; i++)
	{
		if (depth[i].size() == 0) continue;
		if (depth[i].size() == 1)
		{
			ans = min(ans, n - 1 - i);
			continue;
		}
		int tmp = 0;
		for (int j = 1; j < depth[i].size(); j++)
			tmp += h[LCA(depth[i][j - 1], depth[i][j])];
		ans = min(ans, n - 1 - ((int)depth[i].size() * i - tmp));
	}
	cout << ans << '\n';	
}

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
