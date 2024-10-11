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

int n;
ll arr[maxn];

ll comb(int n) { return (n < 2 ? 0ll : 1ll * (n - 1) * n / 2); }

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	cin >> n;
	vector<ll> diff;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if (i != 1) diff.push_back(arr[i] - arr[i - 1]);
	}
	
	ll res = n;
	ll tmp = 0;
	int cur = 1;
	for (int i = 1; i < diff.size(); i++)
		if (diff[i] == diff[i - 1])
			cur++;
		else
		{
			res += comb(cur + 1);
			tmp += cur;
			cur = 1;
		}
	res += comb(cur + 1);
	tmp += cur;
	
	cout << res + n - 1 - tmp << '\n';

	return 0;
}
