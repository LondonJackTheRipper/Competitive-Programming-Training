#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 1e5 + 9;

struct Edge
{
	int u, v;
	bool isreverse;
	bool isused;
	
	Edge(int u = 0, int v = 0) : u(u), v(v), isreverse(0), isused(0) {}
	bool reverse(int a, int b)
	{
		if (a != u) return true;
		return false;
	}
};

vector<pair<int, int>> adj[maxn];
vector<Edge> edges;
int low[maxn], num[maxn];
int bridges = 0;
int n, m;

int timeDFS = 0;
void DFS(int u, int p = -1)
{
	low[u] = num[u] = ++timeDFS;
	
	for (pair<int, int> nxt : adj[u])
	{
		int v = nxt.first;
		int idx = nxt.second;
		
		if (edges[idx].isused == 0)
		{
			edges[idx].isused = 1;
			edges[idx].isreverse = edges[idx].reverse(u, v);	
		}
		
		if (v == p) continue;
		if (num[v] == 0)
		{
			DFS(v, u);
			
			low[u] = min(low[u], low[v]);
			
			if (low[v] == num[v]) bridges++;
		} else 
			low[u] = min(low[u], num[v]);
	}
}

int main()
{
   faster();

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; 
		cin >> u >> v;
		edges.push_back({u, v});
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	
	DFS(1);
	
	if (bridges > 0)
	{
		cout << 0 << '\n';
		return 0;
	}
	
	for (Edge e : edges)
		if (e.isreverse)
			cout << e.v << ' ' << e.u << '\n';
		else
			cout << e.u << ' ' << e.v << '\n';

	return 0;
}
