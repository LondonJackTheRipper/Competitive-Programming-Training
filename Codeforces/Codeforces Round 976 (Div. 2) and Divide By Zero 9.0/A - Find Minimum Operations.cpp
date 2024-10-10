#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98
  
  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define int long long

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
	
	if (k == 1)
	{
		cout << n << '\n';
		continue;
	}
	
	int p = 1;
	while (p <= n)
	{
		p *= k;
	}
	if (p % k == 0) p /= k;
	
	int turns = 0;
	while (n)
	{
		while (p > n && p % k == 0)
		{
			p /= k;
		}
		int num = n / p;
		n -= num * p;
		turns += num;
	}
	
	cout << turns << '\n';
	}

	return 0;
}
