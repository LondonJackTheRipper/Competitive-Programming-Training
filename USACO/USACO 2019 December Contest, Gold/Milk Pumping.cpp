#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int, int>
#define ll long long
#define pb push_back

const int maxn = 1009;
const int inf = 1e9 + 7;

struct node
{	
	int v, c, f;
	
	node(int v_, int c_, int f_): v(v_), c(c_), f(f_) {};
};

vector<node> adj[maxn];
int n, m;

int dijkstra(int minf)
{
	priority_queue<ii> pq;
	vector<int> cost(n, inf);
	cost[0] = 0;
	pq.push({0, 0});
	
	while (!pq.empty())
	{
		ii nxt = pq.top();
		pq.pop();
		
		
		if (nxt.second != cost[nxt.first]) continue;
		for (node u : adj[nxt.first])
		{
			int nc = nxt.second + u.c;
		
			if (u.f < minf) continue;
			
			if (cost[u.v] > nc)
			{
				cost[u.v] = nc;
				pq.push({u.v, nc});
			}
		}
	}
	
	return cost[n - 1] == inf ? -1 : cost[n - 1];
}

void input()
{
	cin >> n >> m;
	
	vector<int> flows;
	for (int i = 0; i < m; i++)
	{
		int x, y, c, f; cin >> x >> y >> c >> f;
		
		flows.pb(f);
		adj[--x].pb({--y, c, f});
		adj[y].pb({x, c, f});
	}
	
	int ans = -1;
	for (int flow : flows)
	{
		int cur = dijkstra(flow);
		
		if (cur == -1) continue;
		double ratio = double(flow) / double(cur);
		ans = max(ans, int(ratio * 1000000));
	}
	
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

