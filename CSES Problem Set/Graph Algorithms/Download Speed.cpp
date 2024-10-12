#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  Handle codeforces : quangminh98
  
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const ll oo = 1e18 + 9;
const int maxn = 509;
 
vector<int> adj[maxn];
ll c[maxn][maxn];
int n, m;
 
ll BFS(int s, int t, vector<int>& par)
{
	for (int i = 0; i <= n; i++) par[i] = -1;
	par[s] = -2;
	queue<pair<int, ll>> q;
	q.push({s, oo});
	
	while (!q.empty())
	{
		int u = q.front().first;
		ll flow = q.front().second;
		q.pop();
		
		for (int v : adj[u])
		{
			if (par[v] == -1 && c[u][v])
			{
				ll new_flow = min(flow, c[u][v]);
				par[v] = u;
				
				if (v == t)
					return new_flow;
				
				q.push({v, new_flow});
			}
		}
	}
	
	return 0ll;
}
 
ll max_flow(int s, int t)
{
	ll ans = 0, flow = 0;
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
		int u, v, cap; cin >> u >> v >> cap;
		if (c[u][v] == 0)
		{
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		c[u][v] += cap;
	}
 
	cout << max_flow(1, n) << '\n';
 
	return 0;
}
