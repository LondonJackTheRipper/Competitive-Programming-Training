#include <bits/stdc++.h>
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

void solve(vector<vi> &a, int n, int m)
{
	vi v;
	
	for (int i = 0; i < n && v.empty(); i++)
	{
		vi b = a[i];
		sort(b.begin(), b.end());
		for (int j = 0; j < m; j++) if (b[j] != a[i][j])
			v.pb(j);
	}
	
	if (v.size() == 0)
	{
		cout << 1 << " " << 1 << '\n';
		return;
	}
	
	if (v.size() > 2)
	{
		cout << -1 << '\n';
		return;
	}
	
	for (int i = 0; i < n; i++) 
		swap(a[i][v[0]], a[i][v[1]]);
		
	for (int i = 0; i < n; i++)
		for (int j = 1; j < m; j++) if (a[i][j] < a[i][j - 1])
		{
			cout << - 1 << '\n';
			return;
		}
		
	cout << v[0] + 1 << " " << v[1] + 1 << '\n';
}

void input()
{
	int n, m; cin >> n >> m;
	vector<vi> a(n, vi(m));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	
	solve(a, n, m);
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

