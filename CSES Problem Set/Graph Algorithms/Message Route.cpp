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
int par[maxn], d[maxn], visited[maxn];
queue<int> q;
vi adj[maxn];
int n, m;
 
void BFS(int u)
{
	visited[u] = 1;
	q.push(u);
	d[u] = 1; 
	
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		
		for (int p : adj[v]) if (!visited[p])
		{
			q.push(p);
			visited[p] = 1;
			d[p] = d[v] + 1;
			par[p] = v;
		}
	}
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
	BFS(1);
	
	if (!par[n]) cout << "IMPOSSIBLE\n"; else
	{
		cout << d[n] << '\n';
		vi res; res.pb(n);
		
		while (par[n] != 1) res.pb(par[n]), n = par[n];
		
		cout << 1 << ' ';
		for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << ' ';
		cout << '\n';
	}
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	input();
	
	return 0;
}
