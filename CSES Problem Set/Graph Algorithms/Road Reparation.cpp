#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
struct edge
{
	int u, v, w;	
	edge(int uu, int vv, int ww): u(uu), v(vv), w(ww) {};
};
 
const int maxn = 2e5 + 9;
vector<edge> edges;
int par[maxn], size[maxn];
int n, m;
ll ans = 0;
 
void make_set(int n)
{
	for (int i = 1; i <= n; i++)
		par[i] = i, size[i] = 1;
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
	
	if (size[u] > size[v]) swap(u, v);
	par[u] = v;
	size[v] += size[u];
	return true;
}
 
void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int x, y, weight; cin >> x >> y >> weight;
		edges.pb({x, y, weight});
	}
	make_set(n);
	
	sort(edges.begin(), edges.end(), [](edge &x, edge &y) { return x.w < y.w; });
	for (edge e : edges)
	{
		if (!merge(e.u, e.v)) continue;
		
		ans += e.w;
	}
	
	for (int i = 2; i <= n; i++)
		if (find(i) != find(i - 1))
		{
			cout << "IMPOSSIBLE";
			exit(0);
		}
	cout << ans;
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
