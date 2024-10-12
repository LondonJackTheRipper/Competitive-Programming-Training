#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 9;
vector<int> adj[maxn];
int val[maxn];
int par[maxn];
int sz[maxn];
int h[maxn];
int tp[maxn];
int id[maxn];
int n, q;
 
ll st[4 * maxn];
void update(int head, int l, int r, int pos, int val)
{
	if (pos < l || r < pos) return;
	if (l == r) 
	{
		st[head] = val;
		return;
	}
	
	int mid = l + r >> 1;
	update(2 * head, l, mid, pos, val);
	update(2 * head + 1, mid + 1, r, pos, val);
	
	st[head] = st[2 * head] + st[2 * head + 1];
}
 
ll get(int head, int l, int r, int u, int v)
{
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) return st[head];
	
	int mid = l + r >> 1;
	return get(2 * head, l, mid, u, v) + get(2 * head + 1, mid + 1, r, u, v); 
}
 
void dfs(int u, int p = -1)
{
	sz[u] = 1;
	for (int v : adj[u])
	{
		if (v == p) continue;
		par[v] = u;
		h[v] = h[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
 
int cnt = 0;
void hld(int u, int p, int top)
{
	tp[u] = top;
	id[u] = cnt++;
	update(1, 1, n, id[u], val[u]);
	
	int nxt = 0;
	for (int v : adj[u])
		if (v != p)
			if (nxt == 0 || sz[v] > sz[nxt])
				nxt = v;
				
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
		if (u == tp[u])
		{
			res += val[u];
			u = par[u];
		} else if (h[tp[u]] > h[p])
		{
			res += get(1, 1, n, id[tp[u]], id[u]);
			u = par[tp[u]];
		} else 
		{
			res += get(1, 1, n, id[p] + 1, id[u]);
			break;
		}
	}
	
	return res;
}
 
void input()
{
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) cin >> val[i];
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
		int type, x, y;
		cin >> type >> x;
		
		if (type == 1)
		{
			cin >> y;
			val[x] = y;
			update(1, 1, n, id[x], val[x]);
		} else 
			cout << queries(x, 1) + val[1] << '\n';
	}
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
	
	return 0;
}
