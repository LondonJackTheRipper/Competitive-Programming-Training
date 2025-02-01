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
    int n, w; cin >> n >> w;
    vector<pair<int, int>> cols[w + 1];
    vector<int> mx(n + 1, 0), hier(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        cols[x].push_back({y, i + 1});
    }
    int mn = 1e9;
    for (int i = 1; i <= w; i++)
    {
        sort(cols[i].begin(), cols[i].end());
        mn = min(mn, (int)cols[i].size());
        for (int j = 0; j < (int)cols[i].size(); j++)
        {
            mx[j + 1] = max(mx[j + 1], cols[i][j].first);
            hier[cols[i][j].second] = j + 1;
        }
    }

    int q; cin >> q;
    while (q--)
    {
        int t, a; cin >> t >> a;

        if (hier[a] > mn)
            cout << "Yes\n";
        else
            cout << (mx[hier[a]] > t ? "Yes\n" : "No\n");
    }
}
