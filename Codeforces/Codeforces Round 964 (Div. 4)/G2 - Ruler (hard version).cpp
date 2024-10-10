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
int ask(int x, int y)
{
	cout << "? " << x << ' '  << y << endl;
	int res; cin >> res;
	return res;
}

void rep(int x)
{
	cout << "! " << x << endl;
}

void solve()
{
    int l = 2, r = 999;
    int ans = -1;

    while (l < r)
    {
        int a = l + (r - l) / 3;
        int b = r - (r - l) / 3;

        int res = ask(a, b);

        if (res == a * (b + 1))
        {
        	ans = a + 1;
            l = a + 1;
            r = b;
        } else
        if (res == (a + 1) * (b + 1))
        {
        	ans = a;
        	r = a;
		}
        else
        {
        	ans = b + 1;
        	l = b + 1;
		}
    }

    rep(ans);
}
