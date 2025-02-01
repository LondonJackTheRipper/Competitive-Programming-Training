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
    int n, m; cin >> n >> m;
    char s[n][n], t[m][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> t[i][j];

    for (int i = 0; i < n - m + 1; i++)
        for (int j = 0; j < n - m + 1; j++)
        {
            bool flag = true;
            for (int u = i; u < i + m; u++)
                for (int v = j; v < j + m; v++)
                    if (s[u][v] != t[u - i][v - j])
                        flag = false;
            if (flag == true)
            {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return;
            }
        }
}
