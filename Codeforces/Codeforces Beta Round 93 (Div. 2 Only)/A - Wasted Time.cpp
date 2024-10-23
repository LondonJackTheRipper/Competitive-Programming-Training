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
    int n, k; cin >> n >> k;
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        points.push_back({x, y});
    }

    long double res = 0;
    for (int i = 1; i < n; i++)
        res += dist(points[i - 1].first, points[i - 1].second, points[i].first, points[i].second);

    cout << fixed << setprecision(6) << (res / 50) * k << '\n';
}
