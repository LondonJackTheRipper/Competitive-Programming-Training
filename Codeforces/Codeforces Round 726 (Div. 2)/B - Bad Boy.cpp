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
int mah(int a, int b, int x, int y) { return abs(x - a) + abs(y - b); }

void solve()
{
    int n, m, i, j; cin >> n >> m >> i >> j;

    int x1 = i, y1 = j;
    vector<pair<int, int>> proc = {{1, m}, {1, 1}, {n, 1}, {n, m}};
    for (pair<int, int> t : proc)
        if (mah(t.first, t.second, x1, y1))
        {
            x1 = t.first;
            y1 = t.second;
        }

    cout << 1 << ' ' << 1 << ' ' << x1 << ' ' << y1 << '\n';
}
