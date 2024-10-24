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

    int res = 1e9;
    for (int x = 0; x <= n; x++)
    {
        if ((n - x) % 2 == 1) continue;
        int y = (n - x) / 2;

        if ((x + y) % m == 0)
            res = min(res, x + y);
    }

    cout << (res == 1e9 ? -1 : res) << '\n';
}
