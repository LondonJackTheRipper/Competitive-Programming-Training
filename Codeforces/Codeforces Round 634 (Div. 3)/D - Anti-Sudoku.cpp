#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

string name = "test";

void solve();
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

// main program

void solve()
{
    char c[10][10];
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            cin >> c[i][j];

    vector<int> tmp = {2, 3, 1};
    vector<vector<int>> mark(10, vector<int>(10, 0));
    for (int i = 1; i <= 9; i += 3)
        for (int u = i; u <= i + 2; u++)
            for (int v = 1; v <= 9; v++)
                if (c[u][v] == '9' && mark[u][v] == 0)
                {
                    c[i - 1 + tmp[u - i]][v] = '9';
                    mark[u][v] = mark[i - 1 + tmp[u - i]][v] = 1;
                }

    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            cout << c[i][j];
            if (j == 9) cout << '\n';
        }
}
