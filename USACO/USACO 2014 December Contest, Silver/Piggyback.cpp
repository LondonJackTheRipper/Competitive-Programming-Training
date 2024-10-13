#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

const int maxn = 40009;
const int inf = 1e9 + 7;

vector<vector<int>> d(maxn, vector<int>(5, -1));
vector<int> adj[maxn];
int b, e, p, n, m;

void bfs(int u, int num)
{
	queue<pair<int, int>> q;
	q.push({u, 0});
	d[u][num] = 0;
	
	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		
		for (int v : adj[p.first])
		{
			if (d[v][num] != -1) continue;
			d[v][num] = p.second + 1;
			q.push({v, d[v][num]});
		}
	}
}

void input()
{
	cin >> b >> e >> p >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	bfs(1, 0);
	bfs(2, 1);
	bfs(n, 2);
	ll ans = inf;
	
	for (int i = 1; i <= n; i++)
		ans = min(ans, 1ll * b * d[i][0] + 1ll * e * d[i][1] + 1ll * p * d[i][2]);
		
	cout << ans << '\n';	
}

int main()
{
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
//	faster();

	input();

	return 0;
}

