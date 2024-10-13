#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

const string name = "speeding";

void solve();
signed main()
{
	if (fopen((name + ".in").c_str(), "r"))
	{
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
//	cin >> t;
	while (t--) solve();

	return 0;
}

const int maxn = 109;

int n, m;
int pre1[maxn], pre2[maxn];
vector<pair<int, int>> roads, speed;

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		roads.push_back({a, b});
		pre1[i] = (i == 0 ? 0 : pre1[i - 1]) + a;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		speed.push_back({a, b});
		pre2[i] = (i == 0 ? 0 : pre2[i - 1]) + a;
	}
	
	int res = 0;
	for (int i = 1; i <= 100; i++)
	{
		int cur = lower_bound(pre2, pre2 + m, i) - pre2;
		int lim = lower_bound(pre1, pre1 + n, i) - pre1;
		res = max(res, speed[cur].second - roads[lim].second);
	}
	cout << res << '\n';
}

