#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

struct edges
{	
	int u, v, w;
	
	edges(int uu, int vv, int ww) : u(uu), v(vv), w(ww) {};
};

int n;
vector<edges> edge;

struct solve
{
	vector<int> par, sz;
	
	void init(int n)
	{
		par.resize(2 * n, 0);	
		sz.resize(2 * n, 1);
		iota(par.begin(), par.end(), 0);
	}	
	
	int find(int u)
	{
		return u == par[u] ? u : par[u] = find(par[u]);
	}
	
	bool merge(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		par[b] = a;
		sz[a] += sz[b];
		return true;
	}
} dsu;

void input()
{
	cin >> n;
	vector<int> a(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = i - 1; j >= 0; j--)
		{
			int xo = a[i] ^ a[j];
			edge.pb({i + 1, j + 1, xo});
		}
	}
	sort(edge.begin(), edge.end(), [](edges a, edges b)
	{
		return a.w > b.w;
	});
	dsu.init(n);
	ll res = 0;
	
	for (edges e : edge)
	{
		if (!dsu.merge(e.u, e.v))
			continue;
			
		res += e.w;
	}
	
	cout << res << '\n';
}

int main()
{
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
//	faster();

	input();

	return 0;
}

