#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

const int maxn = 1090;

vector<int> adj[maxn];
int sz[maxn];
int n, x;

void reset()
{
	for (int i = 0; i < maxn; i++)
		adj[i].clear(), sz[i] = 0;
}

void dfs(int u, int p)
{
	sz[u] = 1;
	
	for (int v : adj[u])
	{
		if (v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}

void input()
{
	reset();
	cin >> n >> x;
	
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	if (adj[x].size() == 1 || adj[x].size() == 0)
	{
		cout << "Ayush\n";
		return;
	}
	dfs(x, -1);
	
	int turns = 0; // 0 is Ayush, 1 is Ashish
	int outer = 0;
	
	for (int v : adj[x])
		outer += (sz[v] - 1);
	
	if (outer != 0) turns = (outer % 2 == 0 ? 0 : 1);
	string winner = "Ayush";
	int rem = adj[x].size();
	
	if (rem % 2 == 1 && turns == 1)
		winner = "Ashish";
	else 
	if (rem % 2 == 0 && turns == 0)
		winner = "Ashish";
		
	cout << winner << '\n';
	
}

int main()
{
   faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
