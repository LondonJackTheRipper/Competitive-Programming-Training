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

struct arr
{
	int x, w, idx;
};

struct arr a[200005];

bool cmp(struct arr a, struct arr b)
{
	return a.w < b.w;
}

void input()
{
	int n, m; cin >> n >> m;
	
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].x >> a[i].w;
		a[i].idx = i;
	}
	sort(a + 1, a + m + 1, cmp);
	ll res = 0;
	vector<pi> v;
	for (int i = 1; i <= 2 * n; i++)
	{
		res += a[i].w;
		v.pb({a[i].x, a[i].idx});
	}
	sort(v.begin(), v.end());
	cout << res << '\n';
	
	for (lui i = 1; i <= v.size() / 2; i++)
	{
		cout << v[i - 1].second << " " << v[v.size() - i].second << '\n';
	}
	cout << '\n';
}

int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	int t; cin >> t;
	while (t--) input();
	
	return 0;
}

