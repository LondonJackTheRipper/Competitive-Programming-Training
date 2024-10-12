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
 
const int maxn = 2e5 + 9;
int in[maxn], out[maxn];
vector<int> adj[maxn];
int n, c = 0;
 
void dfs(int u, int p)
{
	in[u] = ++c;
	for (int v : adj[u]) if (v != p)
		dfs(v, u);
	out[u] = c;
}
 
void input()
{
	cin >> n;
	
	for (int i = 2; i <= n; i++)
	{
		int x; cin >> x;
		adj[i].pb(x);
		adj[x].pb(i);
	}
	dfs(1, -1);
	
	for (int i = 1; i <= n; i++)
		cout << out[i] - in[i] << ' ';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	
	input();
	
	return 0;
}
