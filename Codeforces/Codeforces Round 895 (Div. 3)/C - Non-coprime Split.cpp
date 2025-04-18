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
    int l, r; cin >> l >> r;

    if (l == r)
    {
        int p = -1;
        for (int i = 2; i * i <= l; i++)
            if (l % i == 0)
            {
                p = i;
                break;
            }
        if (p == -1)
            cout << -1 << '\n';
        else
            cout << (l / p) * (p - 1) << ' ' << l / p << '\n';

        return;
    }

    if (r % 2 == 1)
        r--;

    if (r == 2)
        cout << -1 << '\n';
    else
        cout << r / 2 << ' ' << r / 2 << '\n';
}
