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

	int l, r; cin >> l >> r;
	
	if (l == r && l == 0)
	{
	   cout << "Invalid\n";
	   return 0;
	}
	if ((l & r) == 0)
		cout << (l == 1 ? "Yes\n" : "No\n");
	else
		cout << "Invalid\n";

	return 0;
}
