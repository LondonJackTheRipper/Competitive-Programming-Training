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
		
		int l = n - k + 1, r = n;
		int num = ((r + 1) / 2) - (l / 2);
		
		cout << (num % 2 == 0 ? "YES\n" : "NO\n");
	}

	return 0;
}
