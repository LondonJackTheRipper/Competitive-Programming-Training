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
    int r; cin >> r;

    ll res = 0;
    for (int x = -r; x <= r; x++)
    {
        int left = 0, right = 2 * r;
        int yl = -1;
        while (left <= right)
        {
            int mid = left + right >> 1;
            if (1ll * r * r - 1ll * x * x <= 1ll * mid * mid)
            {
                yl = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }
        left = 0, right = 2 * r;
        int yr = -1;
        while (left <= right)
        {
            int mid = left + right >> 1;
            if (1ll * mid * mid < 1ll * r * r + 2 * r + 1 - 1ll * x * x)
            {
                yr = mid;
                left = mid + 1;
            } else
                right = mid - 1;
        }

        res += yr - yl + 1;
    }

    cout << 2 * res - 2 << '\n';
}
