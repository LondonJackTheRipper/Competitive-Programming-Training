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
		int n; cin >> n;
		vector<pair<int, int>> zeros, ones;
		vector<int> cnt1(n + 10, 0), cnt2(n + 10, 0);
		for (int i = 0; i < n; i++)
		{
			int x, y; cin >> x >> y;
			if (y == 0)
			{
				zeros.push_back({x, y});
				cnt1[x]++;
			}
			else
			{
				ones.push_back({x, y});
				cnt2[x]++;
			}
		}

		ll res = 0;
		for (int i = 0; i <= n; i++)
			if (cnt1[i] > 0 && cnt2[i] > 0)	
			{
				res += (zeros.size() + ones.size() - 2);
			}
		for (pair<int, int> z : zeros)
		{
			int x = z.first;
			if (x == 0) continue;
			if (cnt2[x - 1] > 0 && cnt2[x + 1] > 0)
				res++;
		}
		for (pair<int, int> z : ones)
		{
			int x = z.first;
			if (x == 0) continue;
			if (cnt1[x - 1] > 0 && cnt1[x + 1] > 0)
				res++;
		}
				
		cout << res << '\n';
	}

	return 0;
}
