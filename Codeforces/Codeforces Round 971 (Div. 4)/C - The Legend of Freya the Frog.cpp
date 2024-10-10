#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	int t; cin >> t;
	while (t--)
	{
		ll x, y, k; cin >> x >> y >> k;
		ll a = (x + k - 1) / k;
		ll b = (y + k - 1) / k;
		a <= b ? cout << b * 2 << '\n' : cout << a * 2 - 1 << '\n';
	}

	return 0;
}
