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
int dx[5] = {-1, 1, 0, 0, 0};
int dy[5] = {0, 0, -1, 1, 0};

bool isin(int x, int y) { return (0 < x && 0 < y && max(x, y) < 4); }

void solve()
{
    int a[4][4];
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            cin >> a[i][j];

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
        {
            int num = 0;
            for (int d = 0; d < 5; d++)
            {
                int x = i + dx[d];
                int y = j + dy[d];

                if (!isin(x, y)) continue;

                num += a[x][y];
            }

            cout << ((num & 1) ? 0 : 1);
            if (j == 3) cout << '\n';
        }
}
