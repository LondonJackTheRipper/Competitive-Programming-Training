#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  Handle codeforces : quangminh98
  
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int oo = 1e9 + 9;
const int maxn = 1009;
 
vector<pair<int, int>> g[maxn];
vector<int> adj[maxn];
int c[maxn][maxn], vis[10 * maxn];
int n, m, k;
 
int BFS(int s, int t, vector<int>& par)
{
	for (int i = 1; i <= 9 * maxn; i++) par[i] = -1;
	par[s] = -2;
	queue<pair<int, int>> q;
	q.push({s, oo});
	
	while (!q.empty())
	{
		int u = q.front().first;
		int flow = q.front().second;
		q.pop();
		
		for (int v : adj[u])
		{
			if (par[v] == -1 && c[u][v])
			{
				par[v] = u;
				int new_flow = min(flow, c[u][v]);
				if (v == t)
					return new_flow;
				q.push({v, new_flow});
			}
		}
	}
	return 0;
}
 
int Edmonds(int s, int t)
{
	int flow = 0, ans = 0;
	vector<int> par(10 * maxn, 0);
	
	while (flow = BFS(s, t, par))
	{
		ans += flow;
		int cur = t;
		while (cur != s)
		{
			int prev = par[cur];
			c[prev][cur] -= flow;
			c[cur][prev] += flow;
			cur = prev;
		}
	}
	
	return ans;
}
 
void DFS(int u, vector<int>& res)
{
	if (u != 1) res.push_back(u);
	
	for (pair<int, int> nxt : g[u])
	{
		int v = nxt.first, idx = nxt.second;
		
		if (c[u][v] == 0 && vis[idx] == 0)
		{
			vis[idx] = 1;
			if (v == n + m + 2)
				throw 1;
			DFS(v, res);
		}
	}
}
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	cin >> n >> m >> k;
	int cur = -1;
	for (int i = 1; i <= n; i++) 
	{ 
		c[1][i + 1] = 1; 
		adj[1].push_back(i + 1); 
		adj[i + 1].push_back(1); 
		g[1].push_back({i + 1, ++cur}); 
	}
	for (int i = 1; i <= m; i++) 
	{ 
		c[i + n + 1][n + m + 2] = 1; 
		adj[n + m + 2].push_back(i + n + 1); 
		adj[i + n + 1].push_back(n + m + 2); 
		g[i + n + 1].push_back({n + m + 2, ++cur}); 
	}
	for (int i = 0; i < k; i++)
	{
		int u, v; cin >> u >> v;
		u++; v = v + n + 1;
		if (c[u][v] == 0)
		{
			g[u].push_back({v, ++cur});
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		c[u][v] = 1;
	}
	
	int max_flow = Edmonds(1, n + m + 2);
	
	cout << max_flow << '\n';
	while (max_flow > 0)
	{
		vector<int> res;
		try { DFS(1, res); } catch(...) {}
		
		cout << res[0] - 1 << ' ' << res[1] - n - 1 << '\n';
 
		max_flow--;
	}
	
	return 0;
}
