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
	int n, m, q; cin >> n >> m >> q;
	vector<int> a(n), b(m);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;
	b.erase(unique(b.begin(), b.end()), b.end());
	int j = 0;
	unordered_map<int, int> mp;
	for (int i = 0; i < b.size(); i++)
	{
		if (j == n) break;
		int v = b[i];
		if (mp[v] == 0)
		{
			if (v != a[j])
			{
				cout << "TIDAK\n";
				return;
			} else
				j++;
		}
		mp[v]++;
	}
	cout << "YA\n";
}
