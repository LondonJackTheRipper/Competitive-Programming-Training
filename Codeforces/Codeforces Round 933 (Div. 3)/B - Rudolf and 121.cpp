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
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n - 2; i++)
    {
        if (a[i] < 0)
        {
            cout << "NO\n";
            return;
        }

        int bracket = a[i];
        a[i] -= bracket;
        a[i + 1] -= 2 * bracket;
        a[i + 2] -= bracket;
    }

    cout << (a[n - 1] == 0 && a[n - 2] == 0 ? "YES\n" : "NO\n");
}
