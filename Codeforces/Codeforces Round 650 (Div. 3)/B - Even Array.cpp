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
    int even = 0, odd = 0;
    int teven = 0, todd = 0;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;

        if (i % 2 != x % 2)
        {
            (i % 2 == 0 ? teven++ : todd++);
            (x % 2 == 0 ? even++ : odd++);
        }
    }

    if (even != teven)
    {
        cout << -1 << '\n';
        return;
    }

    cout << min(even, odd) << '\n';
}
