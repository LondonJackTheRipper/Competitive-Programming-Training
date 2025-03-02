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
    int n; cin >> n;
    vector<vector<char>> a(n + 1, vector<char>(n + 1, '#'));

    for (int i = 2; i <= n; i += 2)
    {
        for (int j = i; j <= n - i + 1; j++)
        {
            a[i][j] = a[n - i + 1][j] = '.';
            a[j][i] = a[j][n - i + 1] = '.';
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j];
            if (j == n)
                cout << '\n';
        }
}
