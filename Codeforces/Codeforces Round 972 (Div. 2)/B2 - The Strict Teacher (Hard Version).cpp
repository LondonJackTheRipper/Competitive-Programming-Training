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
	int b[m + 1];
	for (int i = 1; i <= m; i++) cin >> b[i];
	sort(b + 1, b + m + 1);
	
	while (q--)
	{
		int a; cin >> a;
		
		if (a < b[1])
			cout << b[1] - 1 << '\n';
		else
		if (a > b[m])
			cout << n - b[m] << '\n';
		else
		{
			int pos = upper_bound(b + 1, b + m + 1, a) - b;
			int l = b[pos - 1], r = b[pos];
			int mid = l + r >> 1;
			int ops = abs(a - mid);
			l += ops; r -= ops;
			cout << ops + min(max(0, mid - l), max(r - mid, 0)) << '\n';
		}
	}
}
