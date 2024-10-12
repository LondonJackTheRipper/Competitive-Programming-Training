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
const int maxn = 3009;

char c[maxn][maxn];
int n;

char modify(int x, int y, int turns)
{
    turns %= 4;
    if (turns == 1)
        return c[n + 1 - y][x];
    else
    if (turns == 2)
        return c[n + 1 - x][n + 1 - y];
    else
    if (turns == 3)
        return c[y][n + 1 - x];
    return c[x][y];
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    char res[n + 1][n + 1];
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = i; j <= n + 1 - i; j++)
        {
            res[i][j] = modify(i, j, i);
            res[j][i] = modify(j, i, i);
            res[n + 1 - i][j] = modify(n + 1 - i, j, i);
            res[j][n + 1 - i] = modify(j, n + 1 - i, i);
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cout << res[i][j];
            if (j == n) cout << '\n';
        }
}
