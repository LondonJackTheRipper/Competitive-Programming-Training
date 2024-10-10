#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

string name = "test";

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
	int x, y; cin >> x >> y;
	int res = (y % 2 ? y / 2 + 1 : y / 2);
	int remnant = (y % 2 ? (y / 2) * 7 + 11 : (y / 2) * 7);
	remnant = remnant - x;
	if (remnant >= 0)
		cout << res << '\n'; 
	else 
	{
		remnant = abs(remnant);
		remnant = (remnant % 15 ? remnant / 15 + 1 : remnant / 15);
		cout << res + remnant << '\n';
	}
}
