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
    int b[n];
    for (int i = 0; i < n; i++) cin >> b[i];

    if (n < 3)
    {
        cout << 0;
        return;
    }

    int res = 1e9;
    for (int x = b[0] - 1; x <= b[0] + 1; x++)
        for (int y = b[1] - 1; y <= b[1] + 1; y++)
        {
            int cur_res = abs(x - b[0]) + abs(y - b[1]);
            int d = y - x, prev = y;
            bool flag = true;

            for (int i = 2; i < n; i++)
                if (abs((prev + d) - b[i]) <= 1)
                {
                    prev = prev + d;
                    cur_res += abs(prev - b[i]);
                } else
                {
                    flag = false;
                    break;
                }

            if (flag)
                res = min(res, cur_res);
        }

    cout << (res == 1e9 ? -1 : res) << '\n';
}
