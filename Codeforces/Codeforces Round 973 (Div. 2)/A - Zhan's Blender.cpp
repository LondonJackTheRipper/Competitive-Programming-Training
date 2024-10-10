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
		int n, x, y; cin >> n >> x >> y;
		
		int ans1 = n / x + (n % x != 0);
		int ans2 = n / y + (n % y != 0);
		cout << max(ans1, ans2) << '\n';
	}
	
	return 0;
}
