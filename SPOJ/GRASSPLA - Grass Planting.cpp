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
const int segsize = 4 * maxn;
 
vector<int> adj[maxn];
int par[20][maxn];
int id[maxn];
int tp[maxn];
int sz[maxn];
int h[maxn];
int n, m;
 
// Segment trees
ll st[segsize];
ll lazy[segsize];
 
void pass(int head, int l, int r)
{
	if (l == r || lazy[head] == 0) return;
	
	lazy[2 * head] += lazy[head];
	lazy[2 * head + 1] += lazy[head];
	int mid = l + r >> 1;
	st[2 * head] += (mid - l + 1) * lazy[head];
	st[2 * head + 1] += (r - mid) * lazy[head];
	
	lazy[head] = 0;
}
 
void update(int head, int l, int r, int u, int v)
{
	if (l > v || r < u) return;
	if (u <= l && r <= v)
	{
		st[head] += (r - l + 1);
		lazy[head]++;
		return;
	}
	
	int mid = l + r >> 1;
	pass(head, l, r);
	update(2 * head, l, mid, u, v);
	update(2 * head + 1, mid + 1, r, u, v);
	
	st[head] = st[2 * head] + st[2 * head + 1];
}
 
ll query(int head, int l, int r, int u, int v)
{
	pass(head, l, r);
	if (l > v || r < u) return 0ll;
	if (u <= l && r <= v) return st[head];
	
	int mid = l + r >> 1;
	return query(2 * head, l, mid, u, v) + query(2 * head + 1, mid + 1, r, u, v);
}
// End of segment trees
 
void DFS(int u, int p = -1)
{
	sz[u] = 1;
	for (int v : adj[u])
	{
		if (v == p) continue;
		
		h[v] = h[u] + 1;
		par[0][v] = u;
		for (int i = 1; i < 20; i++)
			par[i][v] = par[i - 1][par[i - 1][v]];
		DFS(v, u);
		sz[u] += sz[v];
	}
}
 
int LCA(int u, int v)
{
	if (h[u] < h[v]) swap(u, v);
	int k = h[u] - h[v];
	
	for (int i = 0; i < 20; i++)
		if (k >> i & 1)
			u = par[i][u];
			
	if (u == v) return u;
	
	for (int i = 19; i >= 0; i--)
		if (par[i][u] != par[i][v])
		{
			u = par[i][u];
			v = par[i][v];
		}
		
	return par[0][u];
}
 
int cnt = 0;
void HLD(int u, int p, int top)
{
	id[u] = ++cnt;
	tp[u] = top;
	
	int nxt = -1;
	for (int v : adj[u])
	{
		if (v == p) continue;
		
		if (nxt == -1 || sz[v] > sz[nxt]) nxt = v; 
	}
	if (nxt != -1) HLD(nxt, u, top);
	
	for (int v : adj[u])
	{
		if (v == p || v == nxt) continue;
		
		HLD(v, u, v);
	}
}
 
void plant(int u, int p)
{
	while (u != p)
		if (tp[u] == u)
		{
			update(1, 1, n, id[u], id[u]);
			u = par[0][u];
		} else 
		if (h[tp[u]] > h[p])
		{
			update(1, 1, n, id[tp[u]], id[u]);
			u = par[0][tp[u]];
		} else
		{
			update(1, 1, n, id[p] + 1, id[u]);
			break;
		}
}
 
ll ask(int u, int p)
{
	ll res = 0;
	
	while (u != p)
		if (tp[u] == u)
		{
			res += query(1, 1, n, id[u], id[u]);
			u = par[0][u];
		} else 
		if (h[tp[u]] > h[p])
		{
			res += query(1, 1, n, id[tp[u]], id[u]);
			u = par[0][tp[u]];
		} else
		{
			res += query(1, 1, n, id[p] + 1, id[u]);
			break;
		}
		
	return res;
}
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	DFS(1);
	HLD(1, -1, 1);
	
	while (m--)
	{
		char type;  
		cin >> type;
		int u, v;
		cin >> u >> v;
			
		int lca = LCA(u, v);
	
		if (type == 'P')
		{
			plant(u, lca);
			plant(v, lca);
		} else 
			cout << ask(u, lca) + ask(v, lca) << '\n';
	}
	
	return 0;
}
