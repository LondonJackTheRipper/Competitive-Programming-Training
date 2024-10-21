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
	int n; cin >> n;
	vector<int> cnt(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		cnt[x]++;
	}
	
	bool res = false;
	for (int i = 0; i <= n; i++)
		if (cnt[i] % 2 == 1)
			res = true;
			
	cout << (res == true ? "YES\n" : "NO\n");
}
