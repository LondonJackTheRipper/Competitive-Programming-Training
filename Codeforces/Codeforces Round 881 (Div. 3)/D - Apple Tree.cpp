#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

const int maxn = 2e5 + 9;

vector<int> adj[maxn];
int cnt[maxn];
int n, q;

void reset()
{
	for (int i = 0; i < maxn; i++)
	{
		adj[i].clear();
		cnt[i] = 0;
	}
}

void dfs(int u, int p)
{
	if (p != -1 && adj[u].size() == 1) cnt[u] = 1;
	
	for (int v : adj[u])
	{
		if (v == p) continue;
		dfs(v, u);
		cnt[u] += cnt[v];
	}
}

void input()
{
	reset();
	cin >> n;
	
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(1, -1);
	
	int q; cin >> q;
	while (q--)
	{
		int u, v; cin >> u >> v;
		
		cout << 1ll * cnt[u] * cnt[v] << '\n';
	}
}

int main()
{
   faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
