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
    int n, m, k; cin >> n >> m >> k;

    int need = (k + n - 1) / n;
    int l = 1, r = need;
    int res = -1;
    while (l <= r)
    {
        int mid = l + r >> 1;

        int can = m / (mid + 1);
        if (1ll * (can + 1) * (mid + 1) - 1 <= m)
            can++;

        int rem = max(0ll, m - 1ll * can * (mid + 1));

        if (rem + 1ll * can * mid >= need)
        {
            res = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }

    cout << res << '\n';
}
