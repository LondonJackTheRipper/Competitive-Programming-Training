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

ll arr[maxn], pre[maxn];
int n, q;

ll segment(int l, int r, ll block)
{
	int lll = (l + (block - 1)) % n == 0 ? n : (l + (block - 1)) % n;
	int rr = (r + (block - 1)) % n == 0 ? n : (r + (block - 1)) % n;
	if (lll <= rr)
		return pre[rr] - pre[lll - 1];
	return pre[n] - pre[lll - 1] + pre[rr];
}

void input()
{
	cin >> n >> q;
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
		sum += arr[i];
	}
	
	while (q--)
	{
		ll l, r; cin >> l >> r;
		ll block1 = (l % n == 0 ? l / n : (l / n) + 1);
		ll block2 = (r % n == 0 ? r / n : (r / n) + 1);
		
		ll ans = max(0ll, block2 - block1 - 1) * sum;
		l = (l % n == 0 ? n : l % n);
		r = (r % n == 0 ? n : r % n);
		if (block1 == block2)
			ans += segment(l, r, block1);
		else
			ans += segment(l, n, block1) + segment(1, r, block2);
		cout << ans << '\n';
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
	while (t--)
	{
		input();
	}

	return 0;
}
