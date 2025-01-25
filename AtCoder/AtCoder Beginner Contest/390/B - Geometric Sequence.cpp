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
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    long double ra = (long double)a[2] / a[1];
    for (int i = 3; i <= n; i++)
        if (((long double)a[i] / a[i - 1]) != ra)
        {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
}
