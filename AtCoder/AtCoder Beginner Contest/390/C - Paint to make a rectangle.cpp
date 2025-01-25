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
    int h, w; cin >> h >> w;
    char c[h + 1][w + 1];
    int mn_h = 1e9, mx_h = 0, mn_w = 1e9, mx_w = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == '#')
            {
                mn_h = min(mn_h, i);
                mx_h = max(mx_h, i);
                mn_w = min(mn_w, j);
                mx_w = max(mx_w, j);
            }
            if (c[i][j] == '?')
                c[i][j] = '#';
        }

    for (int i = mn_h; i <= mx_h; i++)
        for (int j = mn_w; j <= mx_w; j++)
            if (c[i][j] == '.')
            {
                cout << "No\n";
                return;
            }

    cout << "Yes\n";
}
