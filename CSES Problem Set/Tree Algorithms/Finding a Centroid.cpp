#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lui long unsigned int
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 9;
vector<int> adj[maxn];
int size[maxn];
int n;
 
void dfs(int u, int p = -1)
{
	size[u] = 1;
	for (int v : adj[u]) if (v != p)
	{
		dfs(v, u);
		size[u] += size[v];
	}
}
int FindCentroid(int u, int p = -1)
{
	for (int v : adj[u]) if (v != p)
	{
		if (size[v] * 2 > n)
			return FindCentroid(v, u);
	}
	
	return u;
}
 
void input()
{
	cin >> n;
	
	for (int i = 1; i < n; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	
	dfs(1);
	cout << FindCentroid(1) << '\n';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	
	input();
 
	return 0;
}
