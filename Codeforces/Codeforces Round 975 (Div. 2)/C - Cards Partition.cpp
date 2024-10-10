#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98
  
  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 2e5 + 9;

int n;
ll k, mx = 0, s = 0;
ll arr[maxn];

void input()
{
	mx = s = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i], mx = max(mx, arr[i]), s += arr[i];
	
	ll rem = 0;
	for (int i = 1; i <= n; i++) rem += mx - arr[i];
	if (rem <= k)
	{
		cout << n << '\n';
		return;
	}
	
	for (int i = n; i > 0; i--)
	{
		ll div = s % i;
		ll need = (div == 0 ? 0 : i - div);
		if (need > k) continue;
		ll tmp = s; tmp += need;
		tmp += (((k - need) / i) * i);
		ll cc = tmp / i;
		if (cc >= mx)
		{
			cout << i << '\n';
			return;
		}
	}
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
