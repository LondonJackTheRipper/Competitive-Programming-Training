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
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        int p; cin >> p;
        (p % 2 == 1 ? odd++ : even++);
    }

    ll res = 0;
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int q; cin >> q;
        (q % 2 == 1 ? res += odd : res += even);
    }

    cout << res << '\n';
}
