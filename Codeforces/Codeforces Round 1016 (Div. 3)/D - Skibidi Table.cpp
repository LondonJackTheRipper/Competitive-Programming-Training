#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
    int n, q; cin >> n >> q;

    while (q--)
    {
        char c1, c2; cin >> c1 >> c2;

        if (c1 == '-')
        {
            int x, y; cin >> x >> y;

            ll cur = 1;
            for (int i = n - 1; i > 0; i--)
            {
                int sz = (1 << i);
                ll diff = 1ll * sz * sz;
                if (x <= sz)
                    cur += (y > sz ? 3 * diff : 0);
                else
                    cur += (y <= sz ? 2 : 1) * diff;
                if (x > sz) x -= sz;
                if (y > sz) y -= sz;

            }
            if (x == 2 && y == 2) cout << cur + 1; else
            if (x == 2 && y == 1) cout << cur + 2; else
            if (x == 1 && y == 2) cout << cur + 3; else
                cout << cur;
            cout << '\n';
        } else
        {
            ll d; cin >> d;
            ll cur = 1;
            int x = 1, y = 1;
            for (int i = n - 1; i > 0; i--)
            {
                int sz = (1 << i);
                ll diff = 1ll * sz * sz;
                for (int i = 0; i < 4; i++)
                {
                    ll tmp = cur + diff * i;
                    if (tmp <= d && d < tmp + diff)
                    {
                        cur += diff * i;
                        if (i == 1) x += sz, y += sz; else
                        if (i == 2) x += sz; else
                        if (i == 3) y += sz;
                        break;
                    }
                }
            }
            if (d - cur == 1) x++, y++; else
            if (d - cur == 2) x++; else
            if (d - cur == 3) y++;
            cout << x << ' ' << y << '\n';
        }
    }
}
