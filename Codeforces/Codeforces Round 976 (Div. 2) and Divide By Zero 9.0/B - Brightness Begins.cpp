#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98
  
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
		ll k; cin >> k;
		
		ll l = 1, r = 1e18 + 1e9;
		ll res = -1;
		while (l <= r)
		{
			ll mid = (l + r) / 2;
			ll sq = mid - (long long)sqrt(mid);
			if (sq >= k)
			{
				if (sq == k) res = mid; 
				r = mid - 1;
			} else
				l = mid + 1;
		}

		cout << res << '\n';
	}

	return 0;
}
