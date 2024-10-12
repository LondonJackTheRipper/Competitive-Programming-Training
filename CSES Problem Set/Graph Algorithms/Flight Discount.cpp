#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pll pair<long long, long long>
#define vll vector<long long>
#define lui long unsigned int
#define vs vector<string>
#define pi pair<int, int>
#define vc vector<char>
#define vi vector<int>
#define ll long long
#define pb push_back
 
const int maxn = 1e5 + 9;
const ll inf = 1e18 + 9;
vector<pair<int, int>> adj[maxn];
int n, m;
 
void dijkstra(int u)
{
	vector<vector<ll>> d(n + 1, vector<ll> (2, inf)); 
	priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
	pq.push({0, u, 1});
	d[u][1] = 0;
	
	while (!pq.empty())
	{
		vector<ll> next = pq.top(); pq.pop();
		int vertex = next[1], remnant = next[2];
		ll dis = next[0];
		
		if (vertex == n)
		{
			cout << dis << '\n';
			return;
		}
		if (dis > d[vertex][remnant])
			continue;
			
		for (pair<int, int> v : adj[vertex])
		{
			int nextvertex = v.first;
			ll nextdis = v.second;
			
			if (d[nextvertex][remnant] > dis + nextdis)
			{
				d[nextvertex][remnant] = dis + nextdis;
				pq.push({d[nextvertex][remnant], nextvertex, remnant});
			}
			if (remnant == 1 && d[nextvertex][remnant - 1] > dis + (nextdis / 2))
			{
				d[nextvertex][remnant - 1] = dis + (nextdis / 2);
				pq.push({d[nextvertex][remnant - 1], nextvertex, remnant - 1});
			}
		}
	}
}
 
void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int x, y, w; cin >> x >> y >> w;
		adj[x].pb({y, w});
	}
	dijkstra(1);
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	
	input();
 
	return 0;
}
