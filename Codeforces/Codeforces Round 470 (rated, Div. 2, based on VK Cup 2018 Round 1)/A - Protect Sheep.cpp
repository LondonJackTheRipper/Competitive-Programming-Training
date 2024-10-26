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
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void solve()
{
    int r, c; cin >> r >> c;
    char a[r][c], res[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            res[i][j] = a[i][j];
        }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != 'S') continue;

            for (int d = 0; d < 4; d++)
            {
                int ii = i + dx[d];
                int jj = j + dy[d];
                if (min(ii, jj) < 0 || ii >= r || jj >= c) continue;

                if (a[ii][jj] == 'W')
                {
                    cout << "No\n";
                    return;
                }
                if (res[ii][jj] == '.') res[ii][jj] = 'D';
            }
        }

    cout << "Yes\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cout << res[i][j];
            if (j == c - 1) cout << '\n';
        }
}
