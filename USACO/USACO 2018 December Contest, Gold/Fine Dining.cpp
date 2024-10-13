#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

const int maxn = 50009;

struct state
{
	int pos, time, eaten;
	
	state(int p, int t, int e) : pos(p), time(t), eaten(e) {};
	
	bool operator < (const state& other) const
	{
		if (eaten != other.eaten)
			return eaten > other.eaten;
		return time > other.time;
	}	
};

vector<ii> adj[maxn];
vector<vi> dist(maxn, vi(2, -1));
vector<int> haybale(maxn, -1);
int n, m, k;

void dijkstra()
{
	priority_queue<state> pq;
	pq.push({n - 1, 0, 0});
	
	while (!pq.empty())
	{
		state cur = pq.top();
		pq.pop();
		
		if (dist[cur.pos][cur.eaten] != -1) continue;
		dist[cur.pos][cur.eaten] = cur.time;
		
		for (ii v : adj[cur.pos])
			pq.push({v.first, cur.time + v.second, cur.eaten});
		
		if (haybale[cur.pos] != -1 && cur.eaten == 0)
			pq.push({cur.pos, cur.time - haybale[cur.pos], 1});
	}
	
	for (int i = 0; i < n - 1; i++)
		cout << (dist[i][1] <= dist[i][0] ? 1 : 0) << '\n';
	for (int i = 0; i < n - 1; i++)
		cout << dist[i][1] << ' ' << dist[i][0] << '\n';
}

void input()
{
	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++)
	{
		int x, y, w; cin >> x >> y >> w;
		adj[--x].pb({--y, w});
		adj[y].pb({x, w});
	}
	for (int i = 0; i < k; i++)
	{
		int pos, yumi; cin >> pos >> yumi;
		haybale[--pos] = yumi;
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

