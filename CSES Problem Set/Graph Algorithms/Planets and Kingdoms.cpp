#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 1e5 + 9;
vector<int> adj[maxn], rev[maxn];
int visited[maxn], kingdom[maxn];
int n, m, scc = 0;
stack<int> st;
 
void dfs1(int u)
{
	visited[u] = 1;
	
	for (int v : adj[u]) if (!visited[v])
		dfs1(v);
		
	st.push(u);
}
 
void dfs2(int u)
{
	visited[u] = 1;
	kingdom[u] = scc;
	
	for (int v : rev[u]) if (!visited[v])
		dfs2(v);
}
 
void kruskal()
{
	for (int i = 1; i <= n; i++) if (!visited[i])
		dfs1(i);
	for (int i = 1; i <= n; i++) visited[i] = 0;
	
	while (!st.empty())
	{
		int u = st.top(); st.pop();
		
		if (!visited[u])
			scc++, dfs2(u);
	}
}
 
void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		rev[y].pb(x);
	}
	kruskal();
	
	cout << scc << '\n';
	for (int i = 1; i <= n; i++)
		cout << kingdom[i] << ' ';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
