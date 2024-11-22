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
const int maxn = 109;

int n, m;
char c[maxn][maxn], ans[maxn][maxn];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isin(int x, int y) { return 1 <= min(x, y) && x <= n && y <= m; }

void flood_fill(int x, int y, int col)
{
    ans[x][y] = (col == 0 ? 'W' : 'B');

    for (int d = 0; d < 4; d++)
    {
        int xx = x + dx[d];
        int yy = y + dy[d];
        if (!isin(xx, yy) || ans[xx][yy] != '#') continue;

        flood_fill(xx, yy, 1 ^ col);
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
            ans[i][j] = '#';
            if (c[i][j] == '-') ans[i][j] = '-';
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (ans[i][j] == '#')
                flood_fill(i, j, 1);
            cout << ans[i][j];
            if (j == m) cout << '\n';
        }
}
