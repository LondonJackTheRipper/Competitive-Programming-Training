#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

char arr[509][10];

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
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 4; j++)
				cin >> arr[i][j];
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < 4; j++)
				if (arr[i][j] == '#')
				{
					cout << j + 1 << ' ';
					break;
				}
		}
		cout << '\n';
	}

	return 0;
}
