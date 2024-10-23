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

int mah(int a, int b, int x, int y) { return abs(a - x) + abs(b - y); }

void solve()
{
    int n, k; cin >> n >> k;
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        points.push_back({x, y});
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        int a = points[i].first, b = points[i].second;

        for (int j = 0; j < n; j++)
            if (j != i)
                cnt += (mah(a, b, points[j].first, points[j].second) <= k);

        if (cnt == n - 1)
        {
            cout << 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
