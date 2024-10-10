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

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// main program

void solve()
{
    int l = 2, r = 999;

    while (l <= r)
    {
        int mid = l + r >> 1;

        cout << "? " << mid << ' ' << mid << '\n'; cout.flush();
        int res; cin >> res;

        if (res != mid * mid)
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << "! " << l << '\n'; cout.flush();
}

