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
int h[maxn], lift[20][maxn];
vector<int> adj[maxn];
int n, q;
 
void dfs(int u)
{
	for (int v : adj[u]) if (v != lift[0][u])
	{
		lift[0][v] = u;
		for (int i = 1; i <= 19; i++)
			lift[i][v] = lift[i - 1][lift[i - 1][v]];
		h[v] = h[u] + 1;
		dfs(v);
	}
}
 
int lca(int u, int v)
{
	if (h[v] > h[u]) swap(u, v);
	int k = h[u] - h[v];
	for (int i = 0; i <= 19; i++) if ((k >> i) & 1) u = lift[i][u];
	if (u == v) return u;
	
	for (int i = 19; i >= 0; i--) if (lift[i][u] != lift[i][v])
	{
		u = lift[i][u];
		v = lift[i][v];
	}
	
	return lift[0][u];
}
 
void input()
{
	cin >> n >> q;
	
	for (int i = 0; i < n - 1; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1);
	
	while (q--)
	{
		int a, b; cin >> a >> b;
		
		cout << h[a] + h[b] - 2 * 1ll * h[lca(a, b)] << '\n';
	}
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	input();
	
	return 0;
}
