#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98
  
  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

struct Query
{
	int a, d, k;
	
	Query() = default;
	Query(int a, int d, int k) : a(a), d(d), k(k) {}
	
	bool operator < (const Query &other) const { return a < other.a; }	
};

struct DSU
{
	int n;
	vector<int> par, sz;
	
	DSU(int n) : n(n) 
	{
		par.resize(n + 2, 0);
		sz.resize(n + 2, 1);
		for (int i = 1; i <= n; i++) par[i] = i;
	}	
	
	int find(int u) { return (u == par[u] ? u : par[u] = find(par[u])); }
	
	void merge(int u, int v)
	{
		u = find(u);
		v = find(v);
		if (u == v) return;
		
		if (sz[u] > sz[v]) swap(u, v);
		par[u] = v;
		sz[v] += sz[u];
	}
};

vector<pair<int, int>> pos[11][11];
int n, m;

void input()
{
	cin >> n >> m;
	for (int i = 0; i <= 10; i++)
		for (int j = 0; j <= 10; j++)
			pos[i][j].clear();
	
	vector<Query> qr;
	while (m--)
	{
		int a, d, k; cin >> a >> d >> k;
		qr.push_back({a, d, k});
	}
	sort(qr.begin(), qr.end());
	for (Query q : qr)
	{
		int a = q.a, d = q.d, k = q.k;
		int st = a - d * (a / d);
		pos[st][d].push_back({a, k});
	}
	
	DSU dsu(n);
	
	for (int i = 0; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			int cur = 0;
			for (auto it : pos[i][j])
			{
				int st = it.first, cnt = it.second;
				if (cur < st)
					cur = st;
				else
					cnt -= (cur - st) / j;
				while (cnt > 0)
				{
					dsu.merge(cur, cur + j);
					cur = cur + j;
					cnt--;
				}
			}
		}
		
	int cc = 0;
	for (int i = 1; i <= n; i++)
		cc += (dsu.find(i) == i);
	cout << cc << '\n';
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
