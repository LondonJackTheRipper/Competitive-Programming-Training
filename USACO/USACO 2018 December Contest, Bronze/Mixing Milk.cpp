#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

const string name = "mixmilk";

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

void solve()
{
	vector<int> c(3), m(3);
	for (int i = 0; i < 3; i++) cin >> c[i] >> m[i];
	
	int ops = 100;
	int l = 0, r = 1;
	while (ops--)
	{
		int pour = min(c[r] - m[r], m[l]);
		m[l] -= pour;
		m[r] += pour;
		if (l == 0) l = 1, r = 2; else
		if (l == 1) l = 2, r = 0; else
		if (l == 2) l = 0, r = 1;
	}
	
	for (int i = 0; i < 3; i++)	
		cout << m[i] << '\n';
}

