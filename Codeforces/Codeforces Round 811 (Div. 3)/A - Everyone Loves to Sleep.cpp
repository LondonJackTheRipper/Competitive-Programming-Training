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
int bracket(int x, int y, int a, int b)
{
    return (x > a || (x == a && y > b) ? 24 * 60 - 60 * x - y + 60 * a + b : 60 * a + b - 60 * x - y);
}

void solve()
{
    int n, h, m; cin >> n >> h >> m;
    int ans = 1e9;
    while (n--)
    {
        int hh, mm; cin >> hh >> mm;

        ans = min(ans, bracket(h, m, hh, mm));
    }

    cout << ans / 60 << ' ' << ans % 60 << '\n';
}
