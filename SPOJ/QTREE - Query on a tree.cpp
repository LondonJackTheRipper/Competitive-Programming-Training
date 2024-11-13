#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int maxn = 10009;
const int oo = 1e9;
 
struct Edge
{
	int u, v;
	int w, id;
	
	Edge() = default;
	
	Edge(int u, int v, int w, int id) : u(u), v(v), w(w), id(id) {}
};
 
// Segment tree
int st[4 * maxn];
void update(int head, int l, int r, int pos, int val)
{
	if (pos < l || r < pos) return;
	if (l == r)
	{
		st[head] = val;
		return;
	}
	
	int mid = l + r >> 1;
	if (pos <= mid)
		update(2 * head, l, mid, pos, val);
	else
		update(2 * head + 1, mid + 1, r, pos, val);
	st[head] = max(st[2 * head], st[2 * head + 1]);
}
 
int query(int head, int l, int r, int u, int v)
{
	if (l > v || r < u) return -oo;
	if (u <= l && r <= v) return st[head];
	
	int mid = l + r >> 1;
	return max(query(2 * head, l, mid, u, v), query(2 * head + 1, mid + 1, r, u, v));
}
// end of segment trees
 
vector<int> adj[maxn];
int arr[maxn];
int pos[maxn];
int h[maxn];
int id[maxn]; 
int tp[maxn]; 
int sz[maxn];
int par[15][maxn];
int n;
 
void DFS(int u, int p = -1)
{
	sz[u] = 1;
	for (int v : adj[u])
	{
		if (v == p) continue;
		
		h[v] = h[u] + 1;
		par[0][v] = u;
		for (int i = 1; i < 15; i++)
			par[i][v] = par[i - 1][par[i - 1][v]];
		DFS(v, u);
		sz[u] += sz[v];
	}
}
 
int LCA(int u, int v)
{
	if (h[u] < h[v]) swap(u, v);
	int k = h[u] - h[v];
	
	for (int i = 0; i < 15; i++)
		if (k >> i & 1)
			u = par[i][u];
		
	if (u == v) return u;
	
	for (int i = 14; i >= 0; i--)
		if (par[i][u] != par[i][v])
		{
			u = par[i][u];
			v = par[i][v];
		}
		
	return par[0][u];
}
 
int num = 0;
void HLD(int u, int p, int head)
{
	tp[u] = head;
	id[u] = ++num;
	update(1, 1, n, id[u], arr[u]);
	
	int nxt = -1;
	for (int v : adj[u])
	{
		if (v == p) continue;
		
		if (nxt == -1 || sz[v] > sz[nxt]) nxt = v;
	} 
	if (nxt != -1) HLD(nxt, u, head);
	
	for (int v : adj[u])
	{
		if (v == p || v == nxt) continue;
		
		HLD(v, u, v);
	}
}
 
int get(int u, int p)
{
	int ans = -oo;
	
	while (u != p)
	{
		if (tp[u] == u)
		{
			ans = max(ans, arr[u]);
			u = par[0][u];
		} else
		if (h[tp[u]] > h[p])
		{
			ans = max(ans, query(1, 1, n, id[tp[u]], id[u]));
			u = par[0][tp[u]];
		} else 
		{
			ans = max(ans, query(1, 1, n, id[p] + 1, id[u]));
			break;
		}
	}
	
	return ans;
}
 
void reset()
{
	num = 0;
	for (int i = 0; i <= n; i++)
	{
		adj[i].clear();
		h[i] = id[i] = tp[i] = sz[i] = pos[i] = 0;
		arr[i] = -oo;
		for (int j = 0; j < 15; j++)
			par[j][i] = 0;
	}	
	for (int i = 0; i <= 4 * n; i++) st[i] = -oo;
}
 
void input()
{
	cin >> n;
	reset();
	
	vector<Edge> edges;
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back({u, v, w, i});
	}
	
	DFS(1);
	for (Edge e : edges)
	{
		int u = e.u, v = e.v;
		if (h[u] > h[v]) swap(u, v);
		
		arr[v] = e.w;
		pos[e.id] = v;
	}
	HLD(1, -1, 1);
	
	string s;
	while (cin >> s)
	{
		if (s == "DONE") break;
		
		if (s == "CHANGE")
		{
			int i, ti; cin >> i >> ti;
			arr[pos[i]] = ti;
			update(1, 1, n, id[pos[i]], ti);
		} else 
		{
			int u, v; cin >> u >> v;
			
			int lca = LCA(u, v);
 
			cout << max(get(u, lca), get(v, lca)) << '\n';
		}
	} 
}
 
signed main()
{
	faster();
 
	int t; cin >> t;
	while (t--) input(); 
 
	return 0;
}
 
