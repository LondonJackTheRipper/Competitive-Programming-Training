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
		int n; cin >> n;
		int arr[n + 1];
		for (int i = 1; i <= n; i++) cin >> arr[i];
		
		int sz1 = 0, mx1 = 0;
		for (int i = 1; i <= n; i += 2) sz1++, mx1 = max(mx1, arr[i]);
		int sz2 = 0, mx2 = 0;
		for (int i = 2; i <= n; i += 2) sz2++, mx2 = max(mx2, arr[i]);
		
		cout << max(sz1 + mx1, sz2 + mx2) << '\n';
	}

	return 0;
}
