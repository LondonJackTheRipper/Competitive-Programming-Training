#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 2e5 + 9;

int n;
ll arr[maxn];

bool solve(ll k)
{
	long long avg = k;
	for (int i = 1; i <= n; i++)
		avg += arr[i];
	avg = avg;
	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		num += ((i == n ? arr[i] + k : arr[i]) * 2 * n < avg);
	}
	return (num > (n / 2));
}

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
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		sort(arr + 1, arr + n + 1);
		
		ll l = 0, r = 1e12;
		ll res = -1;
		while (l <= r)
		{
			ll mid = (l + r) / 2;
			
			bool c = solve(mid);
			
			if (c == true)
			{
				res = mid;
				r = mid - 1;
			} else
				l = mid + 1;
		}
		cout << res << '\n';
	}

	return 0;
}
