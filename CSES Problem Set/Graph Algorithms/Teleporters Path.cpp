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
 
struct edge
{
	int target, id;
	
	edge(int target_, int id_): target(target_), id(id_) {};	
};
 
const int maxn = 1e5 + 9;
vector<edge> adj[maxn];
bool visited[2 * maxn];
int n, m, deg[maxn];
 
list<int> eulerian_path(int u)
{
	list<int> ans;
	ans.pb(u);
	
	while (!adj[u].empty())
	{
		int vertex = adj[u].back().target;
		int num = adj[u].back().id;
		adj[u].pop_back();
		
		if (visited[num]) continue;
		visited[num] = true;
		u = vertex;
		ans.pb(u);
	}
	
	for (auto it = ++ans.begin(); it != ans.end(); it++)
	{
		list<int> t = eulerian_path(*it);
		t.pop_back();
		
		ans.splice(it, t);
	}
	
	return ans;
}
 
bool check()
{
	if (adj[1].size() != deg[1] + 1 || adj[n].size() != deg[n] - 1)
		return false;
	
	for (int i = 2; i < n; i++)
		if (adj[i].size() != deg[i])
			return false;
			
	return true;
}
 
void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].pb({y, i});
		deg[y]++;
	}
	
	if (!check())
	{
		cout << "IMPOSSIBLE\n";
		exit(0);
	}
	
	adj[n].pb({1, m});
	list<int> t = eulerian_path(1);
	
	if (t.size() < m + 1)
		cout << "IMPOSSIBLE\n";
	else 
	{
		for (auto u = t.begin(), v = ++t.begin(); v != t.end(); u++, v++)
			if (*u == n && *v == 1)
			{
				for (auto it = v; it != t.end(); it++)
					cout << *it << ' ';
				for (auto it = ++t.begin(); it != v; it++)
					cout << *it << ' ';
				break;
			}
	}
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	
	input();
 
	return 0;
}
