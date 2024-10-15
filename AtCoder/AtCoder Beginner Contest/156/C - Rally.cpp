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
    int x[n + 1];
    for (int i = 1; i <= n; i++) cin >> x[i];

    int res = 1e9;
    for (int p = 1; p <= 100; p++)
    {
        int cur = 0;
        for (int i = 1; i <= n; i++)
            cur += (x[i] - p) * (x[i] - p);
        res = min(res, cur);
    }
    cout << res << '\n';
}

