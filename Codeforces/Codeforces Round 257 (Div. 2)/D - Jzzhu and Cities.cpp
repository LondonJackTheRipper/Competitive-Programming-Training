#include <bits/stdc++.h>
using namespace std;

/*
  John Watson

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 1e5 + 9;
const ll oo = 1e18 + 9;
int n, m, k;

struct Edge
{
	int u, v;
	ll w;
	
	Edge(int u = 0, int v = 0, ll w = 0ll) : u(u), v(v), w(w) {}	
};

struct Train
{
	int s;
	ll w;
	bool remove;
	
	Train(int s = 0, ll w = 0) : s(s), w(w), remove(0) {}	
};

vector<pair<int, ll>> adj[maxn];
vector<Edge> edges;
vector<Train> trains;
vector<ll> dist(maxn, oo);
int in_deg[maxn];

void dijkstra(int s)
{
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({dist[s] = 0, s});
	
	while (!pq.empty())
	{
		ll w = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		
		if (dist[u] != w) continue;
		
		for (pair<int, ll> nxt : adj[u])
		{
			int v = nxt.first;
			ll ww = nxt.second;
			
			if (dist[v] > dist[u] + ww)
				pq.push({dist[v] = dist[u] + ww, v});
		}
	}
}

int main()
{
   faster();

	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		ll w; cin >> w;
		edges.push_back({u, v, w});
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	for (int i = 0; i < k; i++)
	{
		int s; cin >> s;
		ll w; cin >> w;
		trains.push_back({s, w});
		adj[s].push_back({1, w});
		adj[1].push_back({s, w});
	}
	
	dijkstra(1);
	for (Edge e : edges)
	{
		if (dist[e.u] == dist[e.v] + e.w)
			in_deg[e.u]++;
		if (dist[e.v] == dist[e.u] + e.w)
			in_deg[e.v]++;
	}
	for (Train &t : trains)
	{
		if (dist[t.s] == t.w) // dist[1] = 0
			in_deg[t.s]++;
		else
			t.remove = 1;
	}
	
	int result = 0;
	for (Train &t : trains)
	{
		if (t.remove == 0 && in_deg[t.s] > 1)
		{
			in_deg[t.s]--;
			t.remove = 1;
		}
		
		result += (t.remove == 1);
	}
	
	cout << result << '\n';

	return 0;
}
