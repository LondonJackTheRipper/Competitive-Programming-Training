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
    int n, k; cin >> n >> k;

    if (k == 4)
    {
        vector<int> v(n);
        bool have = 0;
        int cnt = 0;
        for (int &x : v)
        {
            cin >> x;
            cnt += (x % 2 == 0);
            if ((x + 1) % 4 == 0) have = true;
            if (cnt >= 2 || x % 4 == 0)
                cnt = 1e9;
        }
        if (cnt >= 1e9)
        {
            cout << 0 << '\n';
            return;
        }
        if (have)
        {
            cout << 1 << '\n';
            return;
        }
        cout << 2 - cnt << '\n';
    } else
    {
        int res = 1e9;
        for (int i = 0; i < n; i++)
        {
            int x; cin >> x;
            res = min(res, (x + k - 1) / k * k - x);
        }
        cout << res << '\n';
    }
}
