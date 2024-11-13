#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  Handle codeforces : quangminh98
  
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
ll C(int k, int n)
{
	if (k > n - k) k = n - k;
	ll res = 1;
	for (int i = 0; i < k; i++)
		res = res * (n - i) / (i + 1);
	return res;
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
	while (t--)
	{
		int n, k; cin >> n >> k;
		cout << C(k - 1, n - 1) << '\n';
	}
 
	return 0;
}
