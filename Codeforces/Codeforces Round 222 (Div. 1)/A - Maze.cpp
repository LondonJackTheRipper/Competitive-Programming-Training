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
const int maxn = 509;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n, m, k, s, cnt = 0;
char c[maxn][maxn];

bool isin(int x, int y) { return 1 <= min(x, y) && x <= n && y <= m; }

void floodfill(int x, int y)
{
    if (cnt == s - k) throw 0;
    cnt++;
    c[x][y] = 'X';

    for (int d = 0; d < 4; d++)
    {
        int xx = x + dx[d];
        int yy = y + dy[d];

        if (!isin(xx, yy) || c[xx][yy] == '#' || c[xx][yy] == 'X') continue;

        floodfill(xx, yy);
    }
}

void solve()
{
    cin >> n >> m >> k;
    int a, b;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == '.')
            {
                s++;
                a = i;
                b = j;
            }
        }

    try { floodfill(a, b); } catch(...) {}

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] == '#')
                cout << '#';
            else
                cout << (c[i][j] == '.' ? 'X' : '.');
            if (j == m) cout << '\n';
        }
}
