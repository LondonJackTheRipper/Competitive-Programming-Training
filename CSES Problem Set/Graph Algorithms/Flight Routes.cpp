#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define pll pair<long long, long long>
#define ll long long
#define pb push_back
 
const int maxn = 1e5 + 9;
 
int n, m, k;
vector<ii> adj[maxn];
 
void dijkstra()
{
	priority_queue<ll> res[n];
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	res[0].push(0);
	pq.push({0, 0});
	
	while (!pq.empty())
	{
		pair<ll, int> tp = pq.top();
		pq.pop();
		
		int cur_p = tp.second;
		ll cur_w = tp.first;
		if (cur_w > res[cur_p].top()) continue;
		
		for (ii nxt : adj[cur_p])
		{
			int nxt_p = nxt.first;
			ll nxt_w = cur_w + nxt.second;
			
			if (res[nxt_p].size() < k)
			{
				res[nxt_p].push(nxt_w);
				pq.push({nxt_w, nxt_p});
			} else
			if (nxt_w < res[nxt_p].top())
			{
				res[nxt_p].pop();
				res[nxt_p].push(nxt_w);
				pq.push({nxt_w, nxt_p});
			}
		}
	}
	
	vector<ll> ans;
	while (!res[n - 1].empty())
	{
		ans.pb(res[n - 1].top());
		res[n - 1].pop();
	}
	reverse(ans.begin(), ans.end());
	
	for (ll x : ans) cout << x << ' ';
}
 
void input()
{
	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++)
	{
		int x, y, w; cin >> x >> y >> w;
		x--; y--;
		adj[x].pb({y, w});
	}
	dijkstra();
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	
	input();
 
	return 0;
}
