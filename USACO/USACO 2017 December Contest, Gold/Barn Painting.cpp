#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98
  
  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int mod = 1e9 + 7;
const int maxn = 1e5 + 9;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int mul(int a, int b) { return 1ll * a * b % mod; }

vector<int> adj[maxn];
int n, k;

int dp[maxn][4];
void DFS_DP(int u, int p = -1)
{
	for (int v : adj[u])
	{
		if (v == p) continue;
		
		DFS_DP(v, u);
		
		dp[u][1] = mul(dp[u][1], add(dp[v][2], dp[v][3]));
		dp[u][2] = mul(dp[u][2], add(dp[v][1], dp[v][3]));
		dp[u][3] = mul(dp[u][3], add(dp[v][1], dp[v][2]));
	}
}

signed main()
{
	if (fopen("barnpainting.in", "r"))
	{
		freopen("barnpainting.in", "r", stdin);
		freopen("barnpainting.out", "w", stdout);
	}
	faster();

	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) dp[i][1] = dp[i][2] = dp[i][3] = 1;
	for (int i = 0; i < k; i++)
	{
		int b, c; cin >> b >> c;
		dp[b][1] = dp[b][2] = dp[b][3] = 0;
		dp[b][c] = 1;
	}
	
	DFS_DP(1);
	
	cout << add(dp[1][1], add(dp[1][2], dp[1][3])) << '\n';
 
	return 0;
}
