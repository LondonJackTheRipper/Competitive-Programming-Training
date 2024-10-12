#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 3e5;
vector<int> adj[maxn], rev[maxn];
int visited[maxn];
int component[maxn];
stack<int> st;
int counter = 0;
int n, m;
 
void add(int a, int b)
{
	adj[a].pb(b);
	rev[b].pb(a);
}
 
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
	component[u] = counter;
	
	for (int v : rev[u]) if (!visited[v])
		dfs2(v);
}
 
void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		char c1, c2; 
		int x1, x2;
		cin >> c1 >> x1 >> c2 >> x2;
		x1--; x2--;
		
		int b1 = c1 == '+' ? 1 : 0;
		int b2 = c2 == '+' ? 1 : 0;
		add(m * (1 - b1) + x1, m * b2 + x2);
		add(m * (1 - b2) + x2, m * b1 + x1);
	}
	
	for (int i = 0; i < 2 * m; i++) if (!visited[i])
		dfs1(i);
	for (int i = 0; i < 2 * m; i++) visited[i] = 0;
	
	while (!st.empty())
	{
		int u = st.top(); st.pop();
		
		if (!visited[u])
			dfs2(u), counter++;
	}
		
	vector<char> ans(m + 1);
	for (int i = 0; i < m; i++)
	{
		if (component[i] == component[i + m])
		{
			cout << "IMPOSSIBLE\n";
			exit(0);
		}
		
		ans[i] = (component[i] < component[i + m] ? '+' : '-');
	}
	
	for (int i = 0; i < m; i++) cout << ans[i] << ' ';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
