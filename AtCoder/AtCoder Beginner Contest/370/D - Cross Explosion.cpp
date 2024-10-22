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
    int h, w, q; cin >> h >> w >> q;

    set<int> rows[h + 1], cols[w + 1];
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            rows[i].insert(j);
            cols[j].insert(i);
        }

    auto erase = [&](int i, int j) { rows[i].erase(j); cols[j].erase(i); };

    while (q--)
    {
        int r, c; cin >> r >> c;

        if (rows[r].find(c) != rows[r].end())
        {
            erase(r, c);
            continue;
        }

        // left
        {
            auto it = rows[r].lower_bound(c);
            if (it != rows[r].begin())
                erase(r, *prev(it));
        }
        // right
        {
            auto it = rows[r].lower_bound(c);
            if (it != rows[r].end())
                erase(r, *(it));
        }
        // up
        {
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin())
                erase(*prev(it), c);
        }
        // down
        {
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].end())
                erase(*(it), c);
        }
    }

    int res = 0;
    for (int i = 1; i <= h; i++)
        res += rows[i].size();

    cout << res << '\n';
}
