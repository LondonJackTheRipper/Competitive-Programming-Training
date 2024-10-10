#include <bits/stdc++.h>
using namespace std;

/*
  John Watson

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const ll oo = 1e18;
const int maxn = 2e5 + 9;

vector<pair<int, int>> adj[maxn];
int horse[maxn];
int n, m, h;

struct state
{
	ll w;
	int cur;
	bool used;
	
	state() = default;
	state(ll w, int cur, bool used) : w(w), cur(cur), used(used) {}
	
    bool operator > (const state &other) const 
	{
        return w > other.w; 
    }
};

vector<vector<ll>> dijkstra(int s)
{
	priority_queue<state, vector<state>, greater<state>> pq;
	vector<vector<ll>> dist(n + 5, vector<ll>(2, oo));
	pq.push({dist[s][horse[s]] = 0, s, horse[s]});
	
	while (!pq.empty())
	{
		int u = pq.top().cur;
		ll w = pq.top().w;
		int use = pq.top().used;
		pq.pop();
		
		if (dist[u][use] != w) continue;
		
		for (pair<int, int> nxt : adj[u])
		{
			int v = nxt.first;
			int newuse = use | horse[v];
			int ww = (use == 1 ? nxt.second / 2 : nxt.second);
			
			if (dist[v][newuse] > dist[u][use] + ww)
				pq.push({dist[v][newuse] = dist[u][use] + ww, v, newuse});
		}
	}
	
	return dist;
}

void input()
{
	cin >> n >> m >> h;
	for (int i = 1; i <= n; i++)
	{
		horse[i] = 0;
		adj[i].clear();
	}
	for (int i = 0; i < h; i++)
	{
		int a; cin >> a;
		horse[a] = 1;
	}
	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	vector<vector<ll>> d1 = dijkstra(1), d2 = dijkstra(n);
	
	ll ans = oo;
	for (int i = 1; i <= n; i++)
		ans = min(ans, max(min(d1[i][0], d1[i][1]), min(d2[i][0], d2[i][1])));
		
	cout << (ans == oo ? -1 : ans) << '\n';
}

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}

