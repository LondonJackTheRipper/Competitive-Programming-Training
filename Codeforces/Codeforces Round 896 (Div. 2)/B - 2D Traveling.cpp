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

ll mah(int x, int y, int a, int b) { return 1ll * abs(x - a) + abs(y - b); }

void solve()
{
    int n, k, a, b; cin >> n >> k >> a >> b;
    a--; b--;
    vector<pair<int, int>> points(n);
    for (pair<int, int> &x : points) cin >> x.first >> x.second;

    ll mn1 = 1e10, mn2 = 1e10;
    for (int i = 0; i < k; i++)
    {
        mn1 = min(mn1, mah(points[a].first, points[a].second, points[i].first, points[i].second));
        mn2 = min(mn2, mah(points[b].first, points[b].second, points[i].first, points[i].second));
    }

    cout << min(mn1 + mn2, mah(points[a].first, points[a].second, points[b].first, points[b].second)) << '\n';
}
