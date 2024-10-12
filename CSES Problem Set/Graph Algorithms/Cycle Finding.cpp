#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
struct edge
{
	int u, v;
	ll w;
	
	edge(int u_, int v_, ll w_): u(u_), v(v_), w(w_) {};
};
 
const ll inf = 1e18;
const int maxn = 3000;
vector<edge> edges;
vector<ll> d(maxn, inf);
int par[maxn];
int n, m;
 
void bellaman_ford(int u)
{
	d[u] = 0;
	
	for (int i = 1; i <= n - 1; i++)
	{
		for (edge e : edges)
		{
			int u = e.u, v = e.v;
			ll w = e.w;
			
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				par[v] = u;
			}
		}
	}
}
 
void cycle_finding()
{
	int neg = -1;
	
	for (edge e : edges)
	{
		int u = e.u, v = e.v;
		ll w = e.w;
		
		if (d[v] > d[u] + w)
		{
			neg = v;
			par[v] = u;
		}
	}
	
	if (neg == -1)
	{
		cout << "NO\n";
		return;
	} else 
	{
		cout << "YES\n";
		vector<int> cycle;
		for (int i = 1; i <= n; i++)
			neg = par[neg];
		for (int v = neg;; v = par[v])
		{
			cycle.pb(v);
			if (v == neg && cycle.size() > 1) break;
		}
		reverse(cycle.begin(), cycle.end());
		
		for (int x : cycle) cout << x << ' ';
		cout << '\n';
	}
}
 
void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		ll ww; cin >> ww;
		edges.pb({a, b, ww});
	}
	bellaman_ford(1);
	cycle_finding();
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
