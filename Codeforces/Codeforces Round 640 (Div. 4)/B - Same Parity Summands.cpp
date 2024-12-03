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

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

// main program

void solve()
{
	int n, k; cin >> n >> k;
	
	if (n % 2 == 0 && n >= 2 * k)
	{
		cout << "YES\n";
		for (int i = 0; i < k - 1; i++) cout << 2 << ' '; cout << n - 2 * (k - 1) << '\n';
		return; 
	} 
	if (n % 2 == 0 && k % 2 == 0 && n >= k)
	{
		cout << "YES\n";
		for (int i = 0; i < k - 1; i++) cout << 1 << ' '; cout << n - (k - 1) << '\n';
		return;
	}
	if (n % 2 == 1 && k % 2 == 1 && n >= k)
	{
		cout << "YES\n";
		for (int i = 0; i < k - 1; i++) cout << 1 << ' '; cout << n - (k - 1) << '\n';
		return;	
	}
	cout << "NO\n";
}
