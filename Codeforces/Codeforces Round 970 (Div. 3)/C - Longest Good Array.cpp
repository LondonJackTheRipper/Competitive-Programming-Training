#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

inline ll sum(int n) { return 1ll * (n + 1) * n / 2; }

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
		ll l, r; cin >> l >> r;
		
		int i = 0;
		while (l + sum(i) <= r) i++;
		cout << i << '\n';
	}

	return 0;
}
