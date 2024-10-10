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

const int maxn = 1e5 + 9;

int n, q;
int x[maxn];

void input()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> x[i];
	vector<ll> num(n, 0);
	num[0] = num[n - 1] = n - 1;
	for (int i = n - 2; i > 0; i--)
		num[i] = (n - i) * i + (n - i - 1);
	sort(num.begin(), num.end());
	unordered_map<ll, ll> mp;
	ll cur = 1, cnt = n - 1;
	for (int i = n - 2; i >= 0; i--)
	{
		mp[cur * cnt] += max(0ll, x[i + 1] - x[i] - 1);
		cur++; cnt--;
	}
	while (q--)
	{
		ll k; cin >> k;
		
		ll res = mp[k];
		int pos1 = lower_bound(num.begin(), num.end(), k) - num.begin();
		if (num[pos1] != k) 
		{
			cout << res << ' ';
			continue;
		}
		int pos2 = upper_bound(num.begin(), num.end(), k) - num.begin();
		cout << res + (pos2 - pos1) << ' ';
	}
	cout << '\n';
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
