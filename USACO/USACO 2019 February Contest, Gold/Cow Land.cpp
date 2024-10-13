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

//
int st[segsize];

void update(int head, int l, int r, int pos, int val)
{
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
	
	st[head] = st[2 * head] ^ st[2 * head + 1];
} 

int query(int head, int l, int r, int u, int v)
{
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) return st[head];
	
	int mid = l + r >> 1;
	return query(2 * head, l, mid, u, v) ^ query(2 * head + 1, mid + 1, r, u, v);
}
//

vector<int> adj[maxn];
int par[20][maxn], h[maxn], sz[maxn], tp[maxn], id[maxn], e[maxn];
int n, q;

void update(int pos, int val) { update(1, 1, n, pos, val); }

//
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

int timeDFS = 0;
void HLD(int u, int p, int head)
{
	id[u] = ++timeDFS;
	tp[u] = head;
	update(id[u], e[u]);
	
	int nxt = -1;
	for (int v : adj[u])
	{
		if (v == p) continue;
		
		if (nxt == -1 || sz[nxt] < sz[v])
			nxt = v;
	}
	
	if (nxt != -1) HLD(nxt, u, head);
	
	for (int v : adj[u])
	{
		if (v == p || v == nxt) continue;
		
		HLD(v, u, v);
	}
}

int queryPath(int u, int p)
{
	int res = 0;
	
	while (u != p)
		if (tp[u] == u)
		{
			res ^= query(1, 1, n, id[u], id[u]);
			u = par[0][u];
		} else
		if (h[tp[u]] > h[p])
		{
			res ^= query(1, 1, n, id[tp[u]], id[u]);
			u = par[0][tp[u]];
		} else
		{
			res ^= query(1, 1, n, id[p] + 1, id[u]);
			break;
		}
		
	return res;
}
//

signed main()
{
	if (fopen("cowland.in", "r"))
	{
		freopen("cowland.in", "r", stdin);
		freopen("cowland.out", "w", stdout);
	}
	faster();

	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> e[i];
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	DFS(1);
	HLD(1, -1, 1);
	
	while (q--)
	{
		int type; cin >> type;
		
		if (type == 1)
		{
			int pos, val; cin >> pos >> val;
			
			update(id[pos], val);
			e[pos] = val;
		} else
		{
			int u, v; cin >> u >> v;
			
			int lca = LCA(u, v);
			
			int ans = e[lca];
			ans ^= queryPath(u, lca) ^ queryPath(v, lca);
			cout << ans << '\n';
		}
	}

	return 0;
}
