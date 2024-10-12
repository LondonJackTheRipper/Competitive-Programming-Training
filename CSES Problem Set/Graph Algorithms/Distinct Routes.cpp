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
const int maxn = 509;
 
vector<pair<int, int>> g[maxn];
vector<int> adj[maxn];
int c[maxn][maxn], vis[maxn];
int n, m;
 
int BFS(int s, int t, vector<int>& par)
{
	for (int i = 1; i <= n; i++) par[i] = -1;
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
	vector<int> par(n + 1, 0);
	int flow = 0, ans = 0;
	
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
	res.push_back(u);
	
	for (pair<int, int> nxt : g[u])
	{
		int v = nxt.first;
		int idx = nxt.second;
		
		if (c[u][v] == 0 && vis[idx] == 0)
		{
			vis[idx] = 1;
			if (v == n)
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
 
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back({v, i});
		adj[u].push_back(v);
		adj[v].push_back(u);
		c[u][v] = 1;
	}
	
	int max_flow = Edmonds(1, n);
 
	cout << max_flow << '\n';
	while (max_flow > 0)
	{
		vector<int> res;
		try { DFS(1, res); } catch(...) {}
		res.push_back(n);
		cout << res.size() << '\n';
		for (int x : res)
			cout << x << ' ';
		cout << '\n';
		
		max_flow--;
	}
 
	return 0;
}
 
