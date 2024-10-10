#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98
  
  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
ll b, c, d; 
bool check(ll x)
{
	return ((x | b) - (x & c) == d);
}

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	int t; cin >>t;
	while (t--)
	{
		cin >> b >> c >> d;
		
		ll cc = abs(c - d);
		if (check(cc)) { cout << cc << '\n'; continue; }
		cc = abs(b - c);
		if (check(cc)) { cout << cc << '\n'; continue; }
		cc = abs(b - d);
		if (check(cc)) { cout << cc << '\n'; continue; }
		cc = (b | c);
		if (check(cc)) { cout << cc << '\n'; continue; }
		cc = (b ^ c);
		if (check(cc)) { cout << cc << '\n'; continue; }
		cc = (b & c);
		if (check(cc)) { cout << cc << '\n'; continue; }
		cc = (c | d);
		if (check(cc)) { cout << cc << '\n'; continue; }
		cc = (c & d);
		if (check(cc)) { cout << cc << '\n'; continue; }
		cc = (c ^ d);
		if (check(cc)) { cout << cc << '\n'; continue; }
		cc = (b ^ d);
		if (check(cc)) { cout << cc << '\n'; continue; }
		cc = (b & d);
		if (check(cc)) { cout << cc << '\n'; continue; }
		cc = (b | d);
		if (check(cc)) { cout << cc << '\n'; continue; }
		cout << -1 << '\n';
	}

	return 0;
}
