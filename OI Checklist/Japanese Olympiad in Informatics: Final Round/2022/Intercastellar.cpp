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
 
int n, q;
ll a[maxn];
pair<int, ll> b[maxn];
 
pair<int, ll> compute(int x)
{
	ll p = 1;
	
	while (x % 2 == 0)
	{
		p = p * 2;
		x /= 2;
	}
	
	return {x, p};
}
 
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
		b[i] = compute(a[i]);
	}
	for (int i = 1; i <= n; i++)
		a[i] = a[i - 1] + b[i].second;
 
	cin >> q;
	while (q--)
	{
		ll x; cin >> x;
		
		int pos = lower_bound(a + 1, a + n + 1, x) - a;
		
		cout << b[pos].first << '\n';
	}
 
	return 0;
}
