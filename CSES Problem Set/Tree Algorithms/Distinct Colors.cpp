#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 9;
vector<int> adj[maxn];
set<int> s[maxn];
int distinct[maxn];
int n;
 
void dfs(int u, int p = -1)
{
	for (int v : adj[u]) if (v != p)
	{
		dfs(v, u);
		
		if (s[v].size() > s[u].size())
			swap(s[v], s[u]);
		for (int v : s[v]) s[u].insert(v);
	}
	
	distinct[u] = s[u].size();
}
 
void input()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		s[i].insert(x);
	}
	for (int i = 1; i < n; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1);
	
	for (int i = 1; i <= n; i++)
		cout << distinct[i] << ' ';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
