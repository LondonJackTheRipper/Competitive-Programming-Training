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
int mah(int a, int b, int x, int y) { return abs(x - a) + abs(y - b); }

void solve()
{
    int h, w, d; cin >> h >> w >> d;
    vector<pair<int, int>> hum;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            char c; cin >> c;
            if (c == '.') hum.push_back({i, j});
        }

    int nn = hum.size(), res = 0;
    for (int i = 0; i < nn; i++)
        for (int j = i + 1; j < nn; j++)
        {
            int cur = 2;
            for (int u = 0; u < nn; u++)
                cur += (u != i && u != j && (mah(hum[i].first, hum[i].second, hum[u].first, hum[u].second) <= d || mah(hum[j].first, hum[j].second, hum[u].first, hum[u].second) <= d));
            res = max(res, cur);
        }

    cout << res << '\n';
}
