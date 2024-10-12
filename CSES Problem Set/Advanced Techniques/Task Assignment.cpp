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
const int maxn = 500;
 
vector<int> adj[maxn];
int c[maxn][maxn], cost[maxn][maxn], cap[maxn][maxn];
int n;
 
void SPFA(int n, int s, vector<int>& par, vector<int>& dist)
{
	par.assign(n + 1, -1);
	dist.assign(n + 1, oo);
	vector<bool> in(n + 1, false);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		in[u] = false;
		
		for (int v : adj[u])
		{
			if (cap[u][v] > 0 && dist[v] > dist[u] + cost[u][v])
			{
				dist[v] = dist[u] + cost[u][v];
				par[v] = u;
				
				if (!in[v])
				{
					in[v] = true;
					q.push(v);
				}
			}
		}
	}
}
 
int min_cost_flow(int k, int s, int t)
{
	int flow = 0, cost = 0;
	vector<int> dist, par;
	
	while (flow < k)
	{
		SPFA(2 * n + 2, s, par, dist);
		if (dist[t] == oo)
			break;
		int f = k - flow;
		int cur = t;
		while (cur != s)
		{
			f = min(f, cap[par[cur]][cur]);
			cur = par[cur];
		}
		
		flow += f;
		cost += f * dist[t];
		cur = t;
		while (cur != s)
		{
			int prev = par[cur];
			cap[prev][cur] -= f;
			cap[cur][prev] += f;
			cur = prev; 	
		}
	}
	
	return cost;
}
 
int vis[maxn];
void DFS(int u, vector<int>& path)
{
	if (u == 2 * n + 2) return;
	if (u != 1) path.push_back(u);
	vis[u] = 1;
	for (int v : adj[u])
	{
	  if (!vis[v] && cap[u][v] == 0)
	  {
	    DFS(v, path);
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
 
	cin >> n;
	for (int i = 2; i <= n + 1; i++)
	  for (int j = n + 2; j <= n + 2 + n - 1; j++)
	    cin >> c[i][j];
			
	for (int i = 2; i <= n + 1; i++)
		for (int j = n + 2; j <= n + 2 + n - 1; j++)
		{
			adj[i].push_back(j);
			adj[j].push_back(i);
			cost[i][j] = c[i][j];
			cost[j][i] = -c[i][j];
			cap[i][j] = 1;
		}
	for (int i = 2; i <= n + 1; i++)
	{
		adj[1].push_back(i);
		adj[i].push_back(1);
		cap[1][i] = 1;
	}
	for (int i = n + 2; i <= n + 2 + n - 1; i++)
	{
		adj[i].push_back(2 * n + 2);
		adj[2 * n + 2].push_back(i);
		cap[i][2 * n + 2] = 1;
	}
 
	cout << min_cost_flow(oo, 1, 2 * n + 2) << '\n';
  for (int i = 2; i <= n + 1; i++)
    for (int j = n + 2; j <= 2 * n + 1; j++)  
    {
      if (cap[i][j] == 0)
      {
        cout << i - 1 << ' ' << j - n - 1 << '\n';
        break;
      }
    }
    
	return 0;
}
