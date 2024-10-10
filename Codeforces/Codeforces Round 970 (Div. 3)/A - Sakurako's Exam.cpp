#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

void input()
{
	int a, b; cin >> a >> b;
	
	for (int i = 0; i <= a; i++)
		for (int j = 0; j <= b; j++)
		{
			if ((-i + a - i - 2 * j + 2 * (b - j)) == 0)
			{
				cout << "YES\n";
				return;
			}	
		}
	cout << "NO\n";	
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
	while (t--) input();

	return 0;
}
