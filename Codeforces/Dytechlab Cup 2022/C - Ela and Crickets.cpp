#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
    int n; cin >> n;
    vector<pair<int, int>> points(3);
    for (pair<int, int> &it : points)
        cin >> it.first >> it.second;
    int p = 0;
    for (int i = 1; i < 3; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 3; j++)
            if (i != j)
                cnt += (points[i].first == points[j].first) + (points[i].second == points[j].second);
        if (cnt == 2)
            p = i;
    }

    int x, y; cin >> x >> y;
    int u = points[p].first, v = points[p].second;
    if ((u == 1 || u == n) && (v == 1 || v == n))
    {
        cout << (x == u || y == v ? "YES\n" : "NO\n");
        return;
    }
    if (x == u || y == v || ((u + v) % 2 != (x + y) % 2) || ((x % 2) == (u % 2) && (y % 2) == (v % 2)))
        cout << "YES\n";
    else
        cout << "NO\n";
}
