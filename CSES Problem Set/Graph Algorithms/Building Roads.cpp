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
bool visited[maxn];
vi adj[maxn], ans;
int n, m, res = -1;
 
void dfs(int u)
{
	visited[u] = 1;
	for (int v : adj[u]) if (!visited[v]) dfs(v);
}
 
void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	
	for (int i = 1; i <= n; i++) if (!visited[i])
	{
		res++;
		dfs(i); 
		ans.pb(i);
	}
	
	cout << res << '\n';
	for (int i = 1; i < ans.size(); i++)
		cout << ans[i - 1] << ' ' << ans[i] << '\n'; 
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	
	input();
	
	return 0;
}
