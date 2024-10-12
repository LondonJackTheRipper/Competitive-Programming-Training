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
 
const int maxn = 2e5 + 9;
vector<int> adj[maxn];
ll st[4 * maxn];
ll val[maxn];
int n, q;
 
int depth[maxn];
int size[maxn];
int par[20][maxn];
int Head[maxn];
int Id[maxn];
 
void update(int head, int l, int r, int p, ll v)
{
	if (p < l || r < p) return;
	if (l == r && l == p)
	{
		st[head] = v;
		return;
	}
	
	int mid = l + r >> 1;
	update(2 * head, l, mid, p, v);
	update(2 * head + 1, mid + 1, r, p, v);
	
	st[head] = max(st[2 * head], st[2 * head + 1]);
}
 
ll get(int head, int l, int r, int u, int v)
{
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) return st[head];
	
	int mid = l + r >> 1;
	
	return max(get(2 * head, l, mid, u, v), get(2 * head + 1, mid + 1, r, u, v));
}
 
void dfs(int u, int p = -1)
{
	size[u] = 1;
	for (int v : adj[u]) if (v != p)
	{
		depth[v] = depth[u] + 1;
		par[0][v] = u;
		for (int i = 1; i < 18; i++)
			par[i][v] = par[i - 1][par[i - 1][v]];
		dfs(v, u);
		size[u] += size[v];
	}
}
 
int LCA(int u, int v)
{
	if (depth[u] < depth[v]) swap(u, v);
	int k = depth[u] - depth[v];
	for (int i = 0; (1 << i) <= k; i++)
		if (k >> i & 1)
			u = par[i][u];
	if (u == v) return u;
	
	k = __lg(depth[u]);
	for (int i = k; i >= 0; i--)
		if (par[i][u] != par[i][v])
		{
			u = par[i][u];
			v = par[i][v];
		}
	return par[0][u];
}
 
int cnt = 1;
void hld(int u, int p, int top)
{
	Id[u] = cnt++;
	Head[u] = top;
	update(1, 1, n, Id[u], val[u]);
	
	int nxt = 0;
	for (int v : adj[u]) if (v != p)
		if (nxt == 0 || size[v] > size[nxt]) nxt = v;
	
	if (nxt) hld(nxt, u, top);
	for (int v : adj[u])
		if (v != p && v != nxt)
			hld(v, u, v);
}
 
ll queries(int u, int p)
{
	ll res = 0;
	
	while (u != p)
	{
		if (u == Head[u])
		{
			res = max(res, val[u]);
			u = par[0][u];
		} else 
		if (depth[Head[u]] > depth[p])
		{
			res = max(res, get(1, 1, n, Id[Head[u]], Id[u]));
			u = par[0][Head[u]];
		} else 
		{
			res = max(res, get(1, 1, n, Id[p] + 1, Id[u]));
			break;
		}
	}
	
	return res;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
		cin >> val[i];
	for (int i = 1; i < n; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	
	dfs(1);
	hld(1, -1, 1);
	
	while (q--)
	{
		int type, x, y; cin >> type >> x >> y;
		
		if (type == 1)
		{
			val[x] = y;
			update(1, 1, n, Id[x], val[x]);
		} else 
		{
			int lca = LCA(x, y);
			cout << max({val[lca], queries(x, lca), queries(y, lca)}) << ' ';
		}
	}	
		
	return 0;
}
