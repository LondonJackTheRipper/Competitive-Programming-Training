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

    if (n % 2 == 0)
    {
        int k = 1;
        while (n % 2 == 0)
        {
            k *= 2;
            n /= 2;
        }

        if (n == 1)
        {
            cout << k / 2 << ' ' << k / 4 << ' ' << k / 4 << '\n';
            return;
        }

        cout << k << ' ' << k * (n / 2) <<  ' ' << k * (n / 2) << '\n';
    } else
        cout << 1 << ' ' << n / 2 << ' ' << n / 2 << '\n';
}
