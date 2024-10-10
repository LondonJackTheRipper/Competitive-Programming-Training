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
const ll mod = 1e9 + 7;

// mathematics compuations
ll add(ll a, ll b) { return ((a % mod) + (b % mod)) % mod; }
ll mul(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
ll comb(int n) { return 1ll * n * (n - 1) / 2; }

ll power(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b % 2 == 1)
			res = mul(res, a);
		a = mul(a, a);
		b /= 2;
	}
	return res;
}

ll inverse(ll a, ll b) { return mul(a, power(b, mod - 2)); }
// end of mathematics

int n;
ll arr[maxn], pre[maxn];

ll segment(int l, int r) { return (l <= r ? pre[r] - pre[l - 1] : 0ll); }

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
	}
	
	ll up = 0;
	ll down = comb(n);
	for (int i = 1; i <= n; i++)
		up = add(up, mul(arr[i], segment(i + 1, n)));

	cout << inverse(up, down) << '\n';
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
