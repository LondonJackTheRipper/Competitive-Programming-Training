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

	int a, b; cin >> a >> b;
	
	set<int> se;
	if ((a + b) % 2 == 0) se.insert((a + b) / 2);
	se.insert(2 * a - b);
	se.insert(2 * b - a);
	
	cout << se.size() << '\n';

	return 0;
}
