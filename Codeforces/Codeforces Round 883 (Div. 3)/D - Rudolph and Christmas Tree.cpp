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
long double area(int d, int h, int up)
{
    long double area1 = 0.5 * d * h;
    long double new_d = 1.0 * d * (h - up) / h;
    long double area2 = 0.5 * new_d * (h - up);
    return area1 - area2;
}

void solve()
{
    int n, d, h; cin >> n >> d >> h;
    int y[n];
    for (int i = 0; i < n; i++) cin >> y[i];

    long double res = area(d, h, h);
    for (int i = n - 2; i >= 0; i--)
        res += area(d, h, min(h, y[i + 1] - y[i]));

    cout << fixed << setprecision(6) << res << '\n';
}
