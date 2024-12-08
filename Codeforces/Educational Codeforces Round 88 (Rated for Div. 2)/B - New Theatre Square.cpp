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
    int n, m, x, y; cin >> n >> m >> x >> y;
    int num = 0, num_block = 0;

    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = 0; j < m; j++)
        {
            char c; cin >> c;

            if (c == '*')
            {
                if (cur != 0) num_block += cur / 2;
                cur = 0;
            } else
            {
                cur++;
                num++;
            }
        }
        if (cur != 0) num_block += cur / 2;
    }

    cout << ((2 * x <= y ? 1ll * num * x : 1ll * (num - 2 * num_block) * x + 1ll * num_block * y)) << '\n';
}
