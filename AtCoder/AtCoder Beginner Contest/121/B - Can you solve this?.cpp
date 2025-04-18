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
    int n, m, c; cin >> n >> m >> c;
    int b[m + 1];
    for (int i = 1; i <= m; i++) cin >> b[i];
    int a[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = c;
        for (int j = 1; j <= m; j++)
            sum += a[i][j] * b[j];
        res += (sum > 0);
    }
    cout << res << '\n';
}
