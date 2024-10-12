#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 1e5 + 9;
 
struct edge
{
	int target, id;
	
	edge(int _target, int _id): target(_target), id(_id) {};	
};
 
vector<edge> adj[maxn];
bool used_edge[2 * maxn];
int n, m, cc;
 
bool check()
{
	for (int i = 1; i <= n; i++)
		if (adj[i].size() % 2)
			return false;
			
	return true;
}
 
list<int> euler(int u)
{
	list<int> ans;
	ans.pb(u);
	
	while (!adj[u].empty())
	{
		int v = adj[u].back().target;
		int uid = adj[u].back().id;
		
		adj[u].pop_back();
		if (used_edge[uid]) continue;
		used_edge[uid] = 1;
		
		u = v;
		ans.pb(u);
	}
	
	for (auto it = ++ans.begin(); it != ans.end(); it++)
	{
		list<int> t = euler(*it);
		
		t.pop_back();
		ans.splice(it, t);
	}
	
	return ans;
}
 
void input()
{
	cin >> n >> m;
	
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].pb({y, ++cnt});
		adj[y].pb({x, cnt});
	}
	
	if (!check())
	{
		cout << "IMPOSSIBLE\n";
		return;
	}
	
	list<int> res = euler(1);
	if (res.size() != m + 1)
	{
		cout << "IMPOSSIBLE\n";
		return;
	}
	
	for (auto it = res.begin(); it != res.end(); it++)
		cout << (*it) << ' '; 
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
