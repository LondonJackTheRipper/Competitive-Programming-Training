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
 
const int maxn = 1e5 + 9;
vector<int> adj[maxn], rev[maxn];
int dp[maxn], visited[maxn], pre[maxn];
stack<int> topo;
int n, m;
 
void dfs(int u)
{
	visited[u] = 1;
	
	for (int v : adj[u]) if (!visited[v])
		dfs(v);
		
	topo.push(u);
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
	dfs(1);
	topo.pop(); dp[1] = 1;
	
	while (!topo.empty())
	{
		int u = topo.top();
		topo.pop();
		for (int v : rev[u])
			if (dp[v] + 1 > dp[u])
			{
				dp[u] = dp[v] + 1;
				pre[u] = v;
			}
	}
	
	if (!dp[n]) cout << "IMPOSSIBLE\n", exit(0);
	cout << dp[n] << '\n';
	vector<int> res;
	while (n != 1)
	{
		res.pb(n);
		n = pre[n];
	}
	res.pb(1);
	for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << ' ';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	
	input();
 
	return 0;
}
