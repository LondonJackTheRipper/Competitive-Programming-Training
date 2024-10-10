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
		int arr[n + 1];
		for (int i = 1; i <= n; i++) cin >> arr[i];
		
		ll res = arr[n - 1];
		for (int i = 1; i < n - 1; i++)
			res -= arr[i];
		cout << arr[n] - res << '\n';
 	} 

	return 0;
}
