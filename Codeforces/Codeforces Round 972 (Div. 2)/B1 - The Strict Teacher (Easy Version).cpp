#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

const string name = "test";

void solve();
signed main()
{
	if (fopen((name + ".inp").c_str(), "r"))
	{
		freopen((name + ".inp").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

// main program

void solve()
{	
	int n, m, q; cin >> n >> m >> q;
	int a, b, c; cin >> a >> b >> c;
	if (a > b) swap(a, b);
	
	if (a < c && c < b)
	{
		int mid = a + b >> 1;
		int ops = abs(c - mid);
		a += ops; b -= ops;
		cout << ops + min(max(0, mid - a), max(b - mid, 0)) << '\n';
	} else
	if (c < a)
	{
		cout << abs(a - 1) << '\n';
	} else
	{
		cout << abs(b - n) << '\n';
	}
}
