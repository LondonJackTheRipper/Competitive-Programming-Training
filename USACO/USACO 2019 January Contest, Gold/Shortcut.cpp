#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

const int maxn = 1e4 + 9;

int n, m, t;
vector<ii> adj[maxn];
int cows[maxn];

void dijkstra()
{
	vi cost(n, INT_MAX), pre(n, INT_MAX);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	cost[0] = 0;
	pq.push({0, 0});
	
	while (!pq.empty())
	{
		ii tp = pq.top();
		pq.pop();
		int cur_pos = tp.second;
		int cur_w = tp.first;
		
		if (cur_w != cost[cur_pos]) continue;
		
		for (ii nxt : adj[cur_pos])
		{
			int nxt_pos = nxt.first;
			int nxt_w = nxt.second;
			
			if (cur_w + nxt_w < cost[nxt_pos])
			{
				cost[nxt_pos] = cur_w + nxt_w;
				pre[nxt_pos] = cur_pos;
				pq.push({cost[nxt_pos], nxt_pos});
			} else 
			if (cur_w + nxt_w == cost[nxt_pos] && cur_pos < pre[nxt_pos])
			{
				pre[nxt_pos] = cur_pos;
				pq.push({cost[nxt_pos], nxt_pos});
			}
		}
	}
	
	vi occur(n, 0);
	for (int i = 0; i < n; i++)
	{
		int tmp = i;
		while (tmp != INT_MAX)
		{
			occur[tmp] += cows[i];
			tmp = pre[tmp];
		}
	}
	
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, 1ll * occur[i] * (cost[i] - t));
		
	cout << ans << '\n';
}

void input()
{
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
		cin >> cows[i];
	for (int i = 0; i < m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		a--; b--;
		adj[a].pb({b, w});
		adj[b].pb({a, w});
	}
	
	dijkstra();
}

int main()
{
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
//	faster();
	
	input();

	return 0;
}

