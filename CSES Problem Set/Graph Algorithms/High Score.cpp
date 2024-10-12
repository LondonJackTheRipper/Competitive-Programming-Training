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
 
const int maxn = 2509;
const ll inf = -1e10;
vector<pair<int, int>> adj[maxn];
vector<ll> d(maxn, inf);
int n, m;
 
void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int x, y, w; cin >> x >> y >> w;
		adj[x].pb({y, w});
	}
	
	d[1] = 0;
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= n; j++) if (d[j] != inf)
			for (pair<int, int> v : adj[j])
			{
				int next = v.first, w = v.second;
				if (d[next] < d[j] + w)
					d[next] = d[j] + w;
			}
			
	for (int i = 1; i <= n; i++) if (d[i] != inf)
		for (pair<int, int> v : adj[i])
		{
			int nextvertex = v.first, dis = v.second;
			if (d[nextvertex] < d[i] + dis)
			{
				vector<bool> visited(n + 1, false);
				queue<int> q; q.push(nextvertex);
				visited[nextvertex] = 1;
				
				while (!q.empty())
				{
					int t = q.front(); q.pop();
					if (t == n) 
					{
						cout << -1 << '\n';
						exit(0);
					}
					
					visited[t] = 1;
					for (pair<int, int> edge : adj[t]) if (!visited[edge.first])
						q.push(edge.first);
				}
			}
		}
		
	cout << d[n] << '\n';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
