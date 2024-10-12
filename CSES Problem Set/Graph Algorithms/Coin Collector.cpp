#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 1e5 + 9;
 
vector<int> adj[maxn], a[maxn];
int low[maxn], num[maxn], c[maxn], tp[maxn];
ll f[maxn], g[maxn];
stack<int> st;
int n, m, scc, cnt;
ll ans;
 
void dfs(int u)
{
	low[u] = num[u] = ++cnt;
	st.push(u);
	
	for (int v : adj[u])
	{
		if (num[v]) low[u] = min(low[u], num[v]);
		else
		{
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
	}
	
	if (low[u] == num[u])
	{
		scc++;
		int v = 0;
		while (u != v)
		{
			v = st.top();
			tp[v] = scc;
			f[scc] += c[v];
			st.pop();
			low[v] = num[v] = n + 1;
		}
	}
}
 
int vis[maxn];
void DFS(int u)
{
	vis[u] = 1;
	for (int v : a[u])
	{
		if (!vis[v])
			DFS(v);
		g[u] = max(g[u], g[v]);
	}
	g[u] += f[u];
	ans = max(ans, g[u]);
}
 
void input()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].pb(y);
	}
	
	for (int i = 1; i <= n; i++) if (!num[i]) dfs(i);
	for (int u = 1; u <= n; u++)
		for (int v : adj[u])
			if (tp[u] != tp[v])
				a[tp[u]].pb(tp[v]); 
				
	for (int i = 1; i <= scc; i++) if (!vis[i])
		DFS(i);
	cout << ans << '\n';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
