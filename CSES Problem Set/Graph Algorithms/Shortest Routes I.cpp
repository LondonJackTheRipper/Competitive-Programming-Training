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
 
const ll inf = 1e18 + 9;
const int maxn = 1e5 + 9;
vector<pair<ll, int>> adj[maxn];
vector<ll> d(maxn, inf);
int n, m;
 
void dijkstra(int u)
{
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	q.push({0, 1});
	d[1] = 0;
	
	while (!q.empty())
	{
		int u = q.top().second, val = q.top().first; q.pop();
		
		if (val > d[u]) continue;
		for (auto it : adj[u])
		{
			int v = it.first, w = it.second;
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				q.push({d[v], v});
			}
		}	
	}
	
	for (int i = 1; i <= n; i++)
		cout << d[i] << ' ';
}
 
void input()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
	input();
 
	return 0;
}
