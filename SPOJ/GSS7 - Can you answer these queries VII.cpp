#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int oo = 1e9 + 7;
const int maxn = 1e5 + 9;
const int segsize = 4 * maxn;
 
// segment tree
struct Node
{
	int pre, suff, finals, sum, lazy;
	
	Node(int val = 0) : sum(val), lazy(oo)
	{
		int tmp = max(0, val);
		pre = suff = finals = tmp;	
	}	
	
	Node operator + (const Node& other)
	{
		if (other.sum == oo) return *this;
		if (sum == oo) return other;
		Node res;
		res.pre = max(pre, sum + other.pre);
		res.suff = max(other.suff, other.sum + suff);
		res.finals = max({finals, other.finals, suff + other.pre});
		res.sum = sum + other.sum;
		return res;
	}
};
 
Node st[segsize];
 
void pass(int head, int l, int r)
{
	if (st[head].lazy == oo) return;
	
	int tmp = st[head].lazy;
	st[head].sum = (r - l + 1) * tmp;
	if (tmp <= 0)
		st[head].pre = st[head].suff = st[head].finals = 0;
	else
		st[head].pre = st[head].suff = st[head].finals = st[head].sum;
	
	if (l != r)
	{
		st[2 * head].lazy = tmp;
		st[2 * head + 1].lazy = tmp;
	}
	
	st[head].lazy = oo;
}
 
void update1(int head, int l, int r, int pos, int val)
{
	pass(head, l, r);
	if (l == r)
	{
		st[head] = Node(val);
		return;
	}
	
	int mid = l + r >> 1;
	if (pos <= mid)
		update1(2 * head, l, mid, pos, val);
	else
		update1(2 * head + 1, mid + 1, r, pos, val);
	
	st[head] = st[2 * head] + st[2 * head + 1];
}
 
void update2(int head, int l, int r, int u, int v, int val)
{
	pass(head, l, r);
	if (l > v || r < u) return;
	if (u <= l && r <= v)
	{
		st[head].lazy = val;
		pass(head, l, r);
		return;
	}
	
	int mid = l + r >> 1;
	update2(2 * head, l, mid, u, v, val);
	update2(2 * head + 1, mid + 1, r, u, v, val);
	
	st[head] = st[2 * head] + st[2 * head + 1];
}
 
Node query(int head, int l, int r, int u, int v)
{
	pass(head, l, r);
	if (l > v || r < u) return Node(oo);
	if (u <= l && r <= v) return st[head];
	
	int mid = l + r >> 1;
	return query(2 * head, l, mid, u, v) + query(2 * head + 1, mid + 1, r, u, v);
}
// end of segment tree
 
vector<int> adj[maxn];
int sz[maxn], h[maxn], par[20][maxn], tp[maxn], id[maxn], v[maxn];
int n, q;
 
// HLD
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
 
int timeDFS = 0;
void HLD(int u, int p, int head)
{
	id[u] = ++timeDFS;
	update2(1, 1, n, id[u], id[u], v[u]);
	tp[u] = head;
	
	int nxt = -1;
	for (int v : adj[u])
	{
		if (v == p) continue;
		
		if (nxt == -1 || sz[v] > sz[nxt])
			nxt = v;
	}
	
	if (nxt != -1)
		HLD(nxt, u, head);
	for (int v : adj[u])
	{
		if (v == p || v == nxt) continue;
		
		HLD(v, u, v);
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
 
void updatePath(int u, int p, int val)
{
	while (u != p)
		if (tp[u] == u)
		{
			update2(1, 1, n, id[u], id[u], val);
			u = par[0][u];
		} else
		if (h[tp[u]] > h[p])
		{
			update2(1, 1, n, id[tp[u]], id[u], val);
			u = par[0][tp[u]];
		} else
		{
			update2(1, 1, n, id[p] + 1, id[u], val);
			break;
		}
}
 
Node queryPath(int u, int p)
{
	Node res = Node(oo);
	
	while (u != p)
		if (tp[u] == u)
		{
			res = query(1, 1, n, id[u], id[u]) + res;
			u = par[0][u];
		} else
		if (h[tp[u]] > h[p])
		{
			res = query(1, 1, n, id[tp[u]], id[u]) + res;
			u = par[0][tp[u]];
		} else
		{
			res = query(1, 1, n, id[p] + 1, id[u]) + res;
			break;
		}
		
	return res;
}
// end of HLD
 
signed main()
{
	if (fopen("GSS7.INP", "r"))
	{
		freopen("GSS7.INP", "r", stdin);
		freopen("GSS7.OUT", "w", stdout);
	}
	faster();
 
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	DFS(1);
	HLD(1, -1, 1);
 
	cin >> q;
	while (q--)
	{
		int type; cin >> type;
		
		if (type == 1)
		{
			int u, v; cin >> u >> v;
			int lca = LCA(u, v); 
			
			Node ans = Node(oo);
			if (u == lca) swap(u, v);
			Node tmp = queryPath(u, lca);			
			ans = ans + tmp;
			ans = query(1, 1, n, id[lca], id[lca]) + ans;
			tmp = queryPath(v, lca);
			swap(tmp.pre, tmp.suff);
			ans = tmp + ans;
			
			cout << ans.finals << '\n';
		} else
		{
			int u, v, c; cin >> u >> v >> c;
			int lca = LCA(u, v);
			
			update2(1, 1, n, id[lca], id[lca], c);
			updatePath(u, lca, c);
			updatePath(v, lca, c);
		}
	}
	
	return 0;
}
 
