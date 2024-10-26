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
char c[8][8];
int res[8][8];

void solve()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == '#')
            {
                for (int k = 0; k < 8; k++)
                    res[i][k] = res[k][j] = 1;
            }
        }

    int ans = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (res[i][j] == 0)
                ans++;

    cout << ans << '\n';
}
