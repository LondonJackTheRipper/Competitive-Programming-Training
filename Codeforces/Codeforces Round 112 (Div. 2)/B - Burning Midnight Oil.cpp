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
    int n, k; cin >> n >> k;

    int l = 0, r = 1e9;
    int res = -1;
    while (l <= r)
    {
        int mid = l + r >> 1;

        ll tmp = 0;
        ll tmp_k = 1;
        while (mid / tmp_k != 0)
        {
            tmp += (mid / tmp_k);
            tmp_k *= k;
        }

        if (tmp >= n)
        {
            res = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }

    cout << res << '\n';
}
