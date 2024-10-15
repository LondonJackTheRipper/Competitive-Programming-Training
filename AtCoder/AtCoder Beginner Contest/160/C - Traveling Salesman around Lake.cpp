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
const int maxn = 2e5 + 9;

int k, n;
int a[maxn], pre[maxn], suff[maxn];

void solve()
{
	cin >> k >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	pre[1] = a[1];
	for (int i = 2; i <= n; i++)
		pre[i] = pre[i - 1] + a[i] - a[i - 1];
	suff[n] = k - a[n];
	for (int i = n - 1; i > 0; i--)
		suff[i] = suff[i + 1] + a[i + 1] - a[i];
		
	int res = 1e9;
	for (int i = 1; i <= n; i++)
	{
		int cur = pre[i - 1] + suff[i];
		if (i == 1) cur -= k - a[n];
		res = min(res, cur);
	}
	cout << res << '\n';
}
