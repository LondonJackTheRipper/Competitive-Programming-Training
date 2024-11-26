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
    int n; cin >> n;
    vector<pair<int, int>> traps(n);
    for (pair<int, int>& x : traps) cin >> x.first >> x.second;

    int l = 0, r = 1000;
    int res = -1;
    while (l <= r)
    {
        int mid = l + r >> 1;

        bool can = true;
        for (pair<int, int> p : traps)
        {
            if (p.first >= mid) continue;
            if (p.second <= max(0, 2 * (mid - p.first)))
                can = false;
        }

        if (can)
        {
            res = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }

    cout << res << '\n';
}
