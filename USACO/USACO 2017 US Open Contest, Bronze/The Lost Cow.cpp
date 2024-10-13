#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

const string name = "lostcow";

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

int x, y;

void solve()
{
	cin >> x >> y;
	
	int cur = 0;
	int path = 0;
	while (1)
	{
		int prev = x + cur;
		if (cur == 0) cur = 1; else cur *= -2;
		int now = x + cur;
		path += abs(now - prev);
		int l = now, r = prev;
		if (l >= r) swap(l, r);
		if (l <= y && y <= r) 
		{
			path -= abs(y - now);
			break;
		}
	}
	
	cout << path << '\n';
}

