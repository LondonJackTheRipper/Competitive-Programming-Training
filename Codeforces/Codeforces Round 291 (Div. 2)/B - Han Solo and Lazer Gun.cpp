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

void solve()
{
    int n, x0, y0; cin >> n >> x0 >> y0;
    vector<pair<int, int>> points(n);
    for (pair<int, int> &it : points)
        cin >> it.first >> it.second;

    int res = 0;
    vector<int> mark(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 1) continue;

        res++;
        mark[i] = 1;
        int x1 = points[i].first, y1 = points[i].second;
        for (int j = 0; j < n; j++)
        {
            if (mark[j] == 1) continue;

            int x2 = points[j].first, y2 = points[j].second;

            if ((y2 - y1) * (x0 - x2) == (x2 - x1) * (y0 - y2))
                mark[j] = 1;
        }
    }

    cout << res << '\n';
}
