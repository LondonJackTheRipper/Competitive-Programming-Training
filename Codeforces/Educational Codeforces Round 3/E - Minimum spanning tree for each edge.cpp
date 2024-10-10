#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 2e5 + 9;
const ll oo = 1e18 + 9;

struct Edge
{
	int u, v;
	int id;
	bool isused;
	ll w;
	
	Edge(int u = 0, int v = 0, int id = 0, ll w = 0ll) : u(u), v(v), id(id), w(w), isused(0) {}	
	
	bool operator < (const Edge& other) const
	{
		return w < other.w;
	}
};

struct Data
{
	int par;
	ll mx;
	
	Data(int par = 0, ll mx = 0ll) : par(par), mx(mx) {}	
};

vector<pair<int, ll>> adj[maxn];
vector<ll> res(maxn, oo);
vector<Edge> edges;
Data up[20][maxn]; 
int d[maxn];
int n, m;

class DSU
{
private:
	vector<int> par;
	vector<int> sz;
public:
	int n;
	
	DSU(int n = 0) : n(n) 
	{
		par.resize(n + 1);
		sz.resize(n + 1, 1);
		
		for (int i = 1; i <= n; i++)
			par[i] = i;	
	}
	
	int find(int u)
	{
		return (u == par[u] ? u : par[u] = find(par[u]));
	}
	
	bool merge(int u, int v)
	{
		u = find(u);
		v = find(v);
		if (u == v) return false;
		
		if (sz[u] > sz[v]) swap(u, v);
		par[u] = v;
		sz[v] += sz[u];
		return true;
	}
};

void DFS(int u, int p = -1)
{	
	for (pair<int, ll> nxt : adj[u])
	{
		int v = nxt.first;
		ll w = nxt.second;
		if (v == p) continue;
		
		d[v] = d[u] + 1;
		up[0][v] = {u, w};
	
		DFS(v, u);
	}
} 

void build()
{
	for (int i = 1; i < 20; i++)
		for (int v = 1; v <= n; v++)
		{
			up[i][v].par = up[i - 1][up[i - 1][v].par].par;
			up[i][v].mx = max(up[i - 1][v].mx, up[i - 1][up[i - 1][v].par].mx);
		}		
}

ll get(int u, int v) // maximum weight of edge in the path from u to v
{
	Data res;
	if (d[u] < d[v]) swap(u, v);
	int k = d[u] - d[v];
	
	for (int i = 0; i < 20; i++)
		if (k >> i & 1)
		{
			res.mx = max(res.mx, up[i][u].mx);
			u = up[i][u].par;
		}
		
	if (u == v)
		return res.mx;
		
	for (int i = 19; i >= 0; i--)
		if (up[i][u].par != up[i][v].par)
		{
			res.mx = max({res.mx, up[i][u].mx, up[i][v].mx});
			u = up[i][u].par;
			v = up[i][v].par;
		}
		
	res.mx = max({res.mx, up[0][u].mx, up[0][v].mx});
	return res.mx;
}

int main()
{
   faster();

	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		ll w; cin >> w;
		
		edges.push_back({u, v, i, w});
	}
	sort(edges.begin(), edges.end());
	
	DSU dsu(n);
	ll minimum_spanning_tree = 0;
	
	for (Edge &e : edges)
		if (dsu.merge(e.u, e.v) == true)
		{
			e.isused = 1;
			adj[e.u].push_back({e.v, e.w});
			adj[e.v].push_back({e.u, e.w});
			minimum_spanning_tree += e.w;
		}
		
	DFS(1);
	build();
	
	for (Edge e : edges)
		if (e.isused == 1)
			res[e.id] = minimum_spanning_tree;
		else
			res[e.id] = minimum_spanning_tree - get(e.u, e.v) + e.w;
		
	for (int i = 0; i < m; i++)
		cout << res[i] << '\n';

	return 0;
}
