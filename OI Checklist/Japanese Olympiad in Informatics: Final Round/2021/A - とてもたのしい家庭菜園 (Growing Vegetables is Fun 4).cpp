#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int maxn = 2e5 + 9;
const ll oo = 1e18;
 
int n;
int a[maxn];
int b[maxn];
ll pre[maxn], suff[maxn];
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		b[i] = a[i]	- a[i - 1];
	}
	
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + max(0, 1 - b[i]);
		suff[n - i + 1] = suff[n - i + 2] + max(0, 1 + b[n - i + 1]);
	}
	
	ll res = 1e18;
	for (int i = 1; i <= n; i++) 
		res = min(res, max(pre[i], suff[i + 1]));
		
	cout << res << '\n';
 
	return 0;
}
