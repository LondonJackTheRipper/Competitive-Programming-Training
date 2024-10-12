#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const ll inf = 1e18 + 9;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 9;
vector<pair<ll, int>> adj[maxn];
vector<ll> dist(maxn, inf);
ll ways[maxn];
int minf[maxn];
int maxf[maxn];
bool visited[maxn];
int n, m;
 
void dijkstra(int u)
{
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({dist[u] = 0, u});
	ways[u] = 1;
	
	while (!pq.empty())
	{
		int vertex = pq.top().second;
		pq.pop();
		
		if (visited[vertex]) continue;
		visited[vertex] = 1;
		
		for (auto v : adj[vertex])
		{
			ll cost = v.first;
			int next = v.second;
			ll nextdis = cost + dist[vertex];
			
			if (nextdis == dist[next])
			{
				ways[next] = (ways[next] + ways[vertex]) % mod;
				minf[next] = min(minf[next], minf[vertex] + 1);
				maxf[next] = max(maxf[next], maxf[vertex] + 1);
			} else if (nextdis < dist[next])
			{
				ways[next] = ways[vertex];
				minf[next] = minf[vertex] + 1;
				maxf[next] = maxf[vertex] + 1;
				pq.push({dist[next] = nextdis, next});
			}
		}
	}
}
 
void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ll w; cin >> w;
		adj[x].pb({w, y});
	}
	dijkstra(1);
	
	cout << dist[n] << ' ' << ways[n] << ' ' << minf[n] << ' ' << maxf[n] << '\n'; 
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
