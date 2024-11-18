#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

const int maxn = 1e5 + 9;

vector<int> adj[maxn];
ll res[maxn];
int c[maxn], mx[maxn];
int n;

void dfs(int u, int p, map<int, int>& large)
{
	res[u] = c[u];
	mx[u] = 1;
	large[c[u]]++;
	
	for (int v : adj[u])
	{
		if (v == p) continue;
		map<int, int> small;
		
		dfs(v, u, small);
		
		if (small.size() > large.size())
		{
			swap(small, large);
			res[u] = res[v];
			mx[u] = mx[v];
		}
		
		for (auto p : small)
		{
			large[p.first] += p.second;
			
			int val = large[p.first];
			if (val > mx[u])
			{
				mx[u] = val;
				res[u] = p.first;
			} else 
			if (val == mx[u])
				res[u] += p.first;
		}
	}
}

int main()
{
   faster();

	cin >> n;
	
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	map<int, int> mp;
	dfs(1, -1, mp);
	
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';

	return 0;
}
