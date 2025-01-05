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
const ll oo = 1e18;

void solve()
{
    int n, m, d; cin >> n >> m >> d;
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    ll res = oo;
    for (int val = 1; val <= (int)1e4; val++)
    {
        ll tmp = 0;
        bool flag = true;
        for (int u = 0; u < n; u++)
            for (int v = 0; v < m; v++)
            {
                if (abs(val - a[u][v]) % d != 0)
                    flag = false;
                tmp += abs(val - a[u][v]) / d;
            }

        if (flag == true)
            res = min(res, tmp);
    }

    cout << (res == oo ? -1 : res) << '\n';
}
