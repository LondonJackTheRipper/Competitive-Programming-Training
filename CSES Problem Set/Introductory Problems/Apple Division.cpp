#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  Handle codeforces : quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define ll long long
 
const string name = "test";
 
void solve();
signed main()
{
	if (fopen((name + ".inp").c_str(), "r"))
	{
		freopen((name + ".inp").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int t = 1;
//	cin >> t;
	while (t--) solve();
 
	return 0;
}
 
const int maxn = 30;
 
int n;
int p[maxn];
 
void solve()
{
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++) cin >> p[i], sum += p[i];
	
	ll res = 1e18;
	
	for (int mask = 0; mask < (1 << n); mask++)
	{
		ll cur = 0;
		for (int i = 0; i < n; i++)
			if (mask >> i & 1)
				cur += p[i];
		res = min(res, abs(cur - (sum - cur)));
	}
	
	cout << res << '\n';
}
