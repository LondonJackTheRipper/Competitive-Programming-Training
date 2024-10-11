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

    int t = 1;
    while (t--) solve();

    return 0;
}

// main program
int C(int n) { return n * (n - 1) / 2; }

void solve()
{
    int n; cin >> n;
    char c[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int row = 0, col = 0;
        for (int j = 1; j <= n; j++)
        {
            if (c[i][j] == 'C') row++;
            if (c[j][i] == 'C') col++;
        }
        res += C(row) + C(col);
    }

    cout << res << '\n';
}
