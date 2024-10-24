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

long double dist(int x, int y, int a, int b) { return sqrt(1ll * (x - a) * (x - a) + 1ll * (y - b) * (y - b)); }

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (abs(a.first) == abs(b.first))
        return abs(a.second) < abs(b.second);
    return abs(a.first) < abs(b.first);
}

void solve()
{
    int n; cin >> n;
    vector<pair<int, int>> rows, cols;
    for (int i = 0; i < 2 * n; i++)
    {
        int x, y; cin >> x >> y;
        if (x == 0)
            cols.push_back({x, y});
        else
            rows.push_back({x, y});
    }

    sort(rows.begin(), rows.end(), cmp);
    sort(cols.begin(), cols.end(), cmp);

    long double res = 0;
    for (int i = 0; i < n; i++)
        res += dist(rows[i].first, 0, 0, cols[i].second);

    cout << fixed << setprecision(9) << res << '\n';
}
