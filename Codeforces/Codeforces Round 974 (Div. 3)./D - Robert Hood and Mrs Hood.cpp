#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int n, d, k;

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
		cin >> n >> d >> k; 
		vector<int> st(n + 5, 0), en(n + 5, 0);
		for (int i = 0; i < k; i++)
		{
			int l, r; cin >> l >> r;
			st[l]++;
			en[r]++;
		}
		int cur = 0;
		for(int j; j <= d; j++)
			cur += st[j];
		int res1 = cur, res2 = cur;
		int d1 = 1, d2 = 1;
		int j = d + 1;
		while (j <= n)
		{
			int rev = j - d;
			cur -= en[rev];
			cur += st[j];
//			cout << rev << ' ' << cur << '\n';
			if (res1 < cur)
			{
				res1 = cur;
				d1 = j - d + 1;
			}
			if (res2 > cur)
			{
				res2 = cur;
				d2 = j - d + 1;
			}
			j++;
		}
		
		cout << d1 << ' ' << d2 << '\n';
	}

	return 0;
}
