#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const ll oo = 1e18;
const int maxn = 1e5 + 9;
 
vector<pair<int, int>> adj[maxn];
int n, m, S, T, U, V;
 
vector<ll> dijkstra(int s)
{
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	vector<ll> dist(n + 2, oo);
	pq.push({dist[s] = 0, s});
	
	while (!pq.empty())
	{
		int u = pq.top().second;
		ll w = pq.top().first;
		pq.pop();
		
		if (dist[u] != w) continue;
		
		for (pair<int, int> nxt : adj[u])
		{
			int v = nxt.first;
			int ww = nxt.second;
			
			if (dist[v] > dist[u] + ww)
				pq.push({dist[v] = dist[u] + ww, v});
		}
	}
	
	return dist;
}
 
ll ans = oo;
int vis[maxn];
vector<ll> dist_u, dist_v, dist_t;
ll dpu[maxn], dpv[maxn];
void magic(int x)
{
	if (vis[x] == 1) return;
	vis[x] = 1;
	
	dpu[x] = dist_u[x];
	dpv[x] = dist_v[x];
	
	for (pair<int, int> nxt : adj[x])
	{
		int v = nxt.first;
		int w = nxt.second;
		if (dist_t[x] != dist_t[v] + w) continue;
		
		magic(v);
		
		dpu[x] = min(dpu[x], dpu[v]);
		dpv[x] = min(dpv[x], dpv[v]);
	}
	
	ans = min({ans, dist_v[x] + dpu[x], dist_u[x] + dpv[x]});
}
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	cin >> n >> m >> S >> T >> U >> V;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		ll w; cin >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	
	dist_u = dijkstra(U);
	dist_v = dijkstra(V);
	dist_t = dijkstra(T);
 
	magic(S);
	
	cout << min(ans, dist_u[V]) << '\n';
 
	return 0;
}
