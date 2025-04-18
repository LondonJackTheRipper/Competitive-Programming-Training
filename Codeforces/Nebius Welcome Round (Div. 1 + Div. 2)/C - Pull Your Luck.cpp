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
    int n, x, p;
    cin >> n >> x >> p;

    int rem = (n - (x % n)) % n, lim = min(2 * n, p);
    for (int i = 1; i <= lim; i++)
    {
        ll s = 1ll * i * (i + 1) / 2;

        if (s % n == rem)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}
