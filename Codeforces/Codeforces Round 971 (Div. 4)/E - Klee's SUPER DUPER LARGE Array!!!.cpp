#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const ll oo = 1e18;

ll segment(ll l, ll r) { return r * (r + 1) / 2 - l * (l - 1) / 2;}

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
		ll n, k; cin >> n >> k;
		ll sum = segment(k, k + n - 1);
		
		ll i = 1, j = n;
		ll res = oo;
		while (i <= j)
		{
			ll mid = i + j >> 1;
			ll cur = segment(k , k + mid - 1);
			
			if (cur < sum - cur)
			{
				i = mid + 1;
				res = min(res, abs(sum - 2 * cur));
			} else
			{
				j = mid - 1;
				res = min(res, abs(sum - 2 * cur));
			}
		}
		cout << res << '\n';
	}

	return 0;
}
