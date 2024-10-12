#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 1e5 + 9;
int par[maxn], size[maxn];
int n, m, mx = 1, cnt;
 
void make_set(int n)
{
	for (int i = 1; i <= n; i++)
		par[i] = i, size[i] = 1;
}
 
int find(int u)
{
	return (u == par[u] ? u : par[u] = find(par[u]));
}
 
bool merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v) return false;
	
	if (size[u] < size[v]) swap(u, v);
	par[v] = u;
	size[u] += size[v];
	return true;
}
 
void input()
{
	cin >> n >> m;
	cnt = n;
	
	make_set(n);
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		
		if (merge(x, y))
			cnt--, mx = max(mx, size[find(x)]);
		cout << cnt << ' ' << mx << '\n';
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
