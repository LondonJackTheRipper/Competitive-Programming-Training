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

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}

// main program

void solve()
{
	int n, x; cin >> n >> x;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		mp[a]++;
	}
	
	for (int i = 0; i <= 2e5; i++)
	{
		if (mp[i] == 0)
		{
			cout << i << '\n';
			return;
		}	
		int bracket = mp[i] - 1;
		mp[i + x] += bracket;
	}
}
