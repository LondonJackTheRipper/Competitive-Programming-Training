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

const int maxn = 5009;

int x[maxn], y[maxn];
int n;

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++) cin >> y[i];
	
	int mx = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			mx = max(mx, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
		
	cout << mx << '\n';
}
