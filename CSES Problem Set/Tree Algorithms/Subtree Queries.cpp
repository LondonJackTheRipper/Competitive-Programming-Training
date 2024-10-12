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
 
const int maxn = 2e5 + 9;
vector<int> adj[maxn];
int val[maxn], in[maxn], out[maxn];
ll sum[4 * maxn];
int n, q, c = 0;
 
void dfs(int u, int p)
{
	in[u] = ++c;
	for (int v : adj[u]) if (v != p)
	{
		dfs(v, u);
	}
	out[u] = c;
}
 
void update(int head, int l, int r, int pos, int val)
{
	if (pos < l || r < pos) return;
	
	if (l == r)
	{
		sum[head] = val;
		return;
	}
	
	int mid = l + r >> 1;
	update(2 * head, l, mid, pos, val);
	update(2 * head + 1, mid + 1, r, pos, val);
	sum[head] = sum[2 * head] + sum[2 * head + 1];
}
 
ll get(int head, int l, int r, int u, int v)
{
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) return sum[head];
	
	int mid = l + r >> 1;
	return get(2 * head, l, mid, u, v) + get(2 * head + 1, mid + 1, r, u, v);
}
 
void input()
{
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) cin >> val[i];
	
	for (int i = 0; i < n - 1; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, -1);
	
	for (int i = 1; i <= n; i++) update(1, 1, n, in[i], val[i]);
	
	while (q--)
	{
		int type, s, x; cin >> type >> s;
		
		if (type == 1) cin >> x, update(1, 1, n, in[s], x); else 
			cout << get(1, 1, n, in[s], out[s]) << '\n';
	}
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	input(); 
	
	return 0;
}
