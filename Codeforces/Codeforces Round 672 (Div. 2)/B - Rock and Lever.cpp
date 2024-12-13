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

    ll res = 0;
    vector<int> cnt(32, 0);
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;

        int highest = 0;
        for (int mask = 0; mask < 32; mask++)
            if (x >> mask & 1)
                highest = mask;

        res += cnt[highest];
        cnt[highest]++;
    }

    cout << res << '\n';
}
