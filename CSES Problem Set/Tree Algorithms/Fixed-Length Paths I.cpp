#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 9;
vector<int> adj[maxn];
int size[maxn], del[maxn], cnt[maxn];
int n, k, mx;
ll ans = 0;
 
int subtree(int u, int p = -1)
{
	size[u] = 1;
	for (int v : adj[u])
		if (v != p && !del[v])
			size[u] += subtree(v, u);
	return size[u]; 
}
 
int findCentroid(int u, int p, int N)
{
	for (int v : adj[u])
		if (v != p && !del[v] && size[v] > N / 2)
			return findCentroid(v, u, N);
	return u;	
}
 
void count(int u, int p, int depth, bool check)
{
	if (depth > k) return;
	mx = max(mx, depth);
	
	if (check)
		cnt[depth]++;
	else
		ans += cnt[k - depth];
	
	for (int v : adj[u])
		if (v != p && !del[v])
			count(v, u, depth + 1, check);
}
 
void centroid_decomposition(int u)
{
	int centroid = findCentroid(u, -1, subtree(u));
	del[centroid] = 1;
	cnt[0] = 1;
	mx = 0;
	
	for (int v : adj[centroid])
		if (!del[v])
		{
			count(v, centroid, 1, false);
			count(v, centroid, 1, true);
		}
	fill(cnt, cnt + mx + 1, 0);
	
	for (int v : adj[centroid])
		if (!del[v])
			centroid_decomposition(v);
}
 
void input()
{
	cin >> n >> k;
	
	for (int i = 1; i < n; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	centroid_decomposition(1);
	
	cout << ans;
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
