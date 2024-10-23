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

    solve();

    return 0;
}

// main program

long double dist(int x, int y, int a, int b) { return sqrt((x - a) * (x - a) + (y - b) * (y - b)); }

void solve()
{
    int a, b; cin >> a >> b;

    long double res = 1e18;
    int n; cin >> n;
    while (n--)
    {
        int x, y, v; cin >> x >> y >> v;
        res = min(res, dist(a, b, x, y) / v);
    }

    cout << fixed << setprecision(6) << res << '\n';
}
