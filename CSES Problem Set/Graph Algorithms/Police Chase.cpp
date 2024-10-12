#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  Handle codeforces : quangminh98
  
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int oo = 1e9;
const int maxn = 509;
 
vector<int> adj[maxn];
int c[maxn][maxn], exist[maxn][maxn];
int n, m;
 
int BFS(int s, int t, vector<int>& par, bool flag = false)
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
				
				if (v == t && !flag)
					return new_flow;
					
				q.push({v, new_flow});
			}
		}
	}
	
	return 0;
}
 
int Edmonds(int s, int t)
{
	int ans = 0, flow = 0;
	vector<int> par(n + 1, 0);
	
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
		adj[u].push_back(v);
		adj[v].push_back(u);
		exist[u][v] = exist[v][u] = 1;
		c[u][v] = c[v][u] = 1;
	}
 
	Edmonds(1, n);
	
	vector<int> par(n + 1, 0);
	BFS(1, n, par, true);
	vector<pair<int, int>> res;
 
 	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (par[i] != -1 && par[j] == -1 && exist[i][j])
				res.push_back({i, j});
				
	cout << res.size() << '\n';
	for (pair<int, int> p : res) 
		cout << p.first << ' ' << p.second << '\n';
	
	return 0;
}
