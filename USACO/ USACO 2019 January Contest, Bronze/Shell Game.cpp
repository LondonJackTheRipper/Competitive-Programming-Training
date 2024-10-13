#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98
  
  Mua Code nhu mua Florentino !!
*/

#define ll long long

const string name = "shell";

void solve();
signed main()
{
	if (fopen((name + ".in").c_str(), "r"))
	{
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1; 
//	cin >> t;
	while (t--) solve();

	return 0;
}

struct sel
{
	int a, b, g;
	
	sel() = default;
	sel(int a, int b, int g) : a(a), b(b), g(g) {}
};
int n;

void solve()
{
	cin >> n;
	vector<sel> sels;
	while (n--)
	{
		int a, b, g; cin >> a >> b >> g;
		sels.push_back({a, b, g});
	}
	
	int res = 0;
	for (int i = 1; i <= 3; i++)
	{
		vector<int> mark(4, 0); mark[i] = 1;
		int cur = 0;
		for (sel s : sels)
		{
			swap(mark[s.a], mark[s.b]);
			cur += mark[s.g];
		}
		res = max(res, cur);
	}
	
	cout << res << '\n';
}
