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
int d[maxn];
vi adj[maxn];
int n, m;
 
void DFS(int u)
{
	for (int v : adj[u])
	{
		if (d[v])
		{
			if (d[u] == d[v])
			{
				cout << "IMPOSSIBLE\n";
				exit(0);
			} 
		}
		else
		{
			d[v] = 3 - d[u];
			DFS(v);
		}
	}
}
 
void input()
{
	int n, m; cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}	
	
	for (int i = 1; i <= n; i++) if (!d[i]) 
	{
		d[i] = 1;
		DFS(i);
	}
		
	for (int i = 1; i <= n; i++)
		cout << d[i] << ' ';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	
	input();
	
	return 0;
}
