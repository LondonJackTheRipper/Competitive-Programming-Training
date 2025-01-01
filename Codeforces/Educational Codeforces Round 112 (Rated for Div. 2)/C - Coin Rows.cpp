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
    int m; cin >> m;
    int a[2][m + 1];
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    vector<int> pre(m + 1, 0), suff(m + 2, 0);
    for (int i = 1; i <= m; i++)
        pre[i] = pre[i - 1] + a[1][i];
    for (int i = m; i > 0; i--)
        suff[i] = suff[i + 1] + a[0][i];

    int mn = 2e9;
    for (int i = 1; i <= m; i++)
        mn = min(mn, max(pre[i - 1], suff[i + 1]));

    cout << mn << '\n';
}
