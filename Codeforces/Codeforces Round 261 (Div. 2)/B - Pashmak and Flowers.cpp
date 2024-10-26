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

// main program

void solve()
{
	int n; cin >> n;
	int b[n + 1];
	for (int i = 1; i <= n; i++) cin >> b[i];
	sort(b + 1, b + n + 1);
	int res = b[n] - b[1];
	cout << res << ' ';
	ll cnt = 0;
	unordered_map<int, int> mp;
	for (int i = 1; i <= n; i++)
	{
		cnt += mp[b[i] - res];
		mp[b[i]]++;
	}
	cout << cnt << '\n';
}
