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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int h, w, k;
char c[20][20];

bool isin(int x, int y) { return (1 <= min(x, y) && x <= h && y <= w); }

ll flood_fill(int x, int y, int rem, vector<vector<int>>& vis)
{
    if (rem == 0) return 1;
    ll res = 0;

    for (int d = 0; d < 4; d++)
    {
        int xx = x + dx[d];
        int yy = y + dy[d];

        if (!isin(xx, yy) || vis[xx][yy] == 1 || c[xx][yy] == '#') continue;

        vis[xx][yy] = 1;
        res += flood_fill(xx, yy, rem - 1, vis);
        vis[xx][yy] = 0;
    }

    return res;
}

void solve()
{
    cin >> h >> w >> k;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> c[i][j];

    ll res = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            if (c[i][j] == '#') continue;

            vector<vector<int>> vis(h + 1, vector<int>(w + 1, 0));
            vis[i][j] = 1;
            res += flood_fill(i, j, k, vis);
        }

    cout << res << '\n';
}
