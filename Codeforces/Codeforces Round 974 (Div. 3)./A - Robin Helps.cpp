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
		int n, k; cin >> n >> k;
		int cur = 0, res = 0;
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			if (x >= k)
				cur += x;
			else
			if (x == 0)
			{
				res += (cur != 0);
				if (cur != 0) cur--;
			}
		}
		cout << res << '\n';
	}

	return 0;
}
