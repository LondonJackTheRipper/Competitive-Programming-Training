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
 
int n, q, s, t;
ll a[maxn], w[maxn];
 
ll calc(ll x) { return x * (x < 0 ? s : t); }
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	cin >> n >> q >> s >> t;
	
	ll cur = 0;
	for (int i = 0; i <= n; i++)
	{
		cin >> a[i];
		w[i] = a[i - 1] - a[i];
		if (i != 0) cur += calc(w[i]);
	}
	
	while (q--)
	{
		int l, r; cin >> l >> r;
		ll x; cin >> x;
		
		cur -= calc(w[l]);
		w[l] -= x;
		cur += calc(w[l]);
		if (r != n)
		{
			cur -= calc(w[r + 1]);
			w[r + 1] += x;
			cur += calc(w[r + 1]);
		}
		
		cout << cur << '\n';
	}
 
	return 0;
}
