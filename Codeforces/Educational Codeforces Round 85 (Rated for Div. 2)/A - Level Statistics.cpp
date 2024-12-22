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
    int p[n], c[n];
    for (int i = 0; i < n; i++) cin >> p[i] >> c[i];

    for (int i = 0; i < n; i++)
        if (p[i] < c[i])
        {
            cout << "NO\n";
            return;
        }
    for (int i = 1; i < n; i++)
        if (p[i] < p[i - 1] || c[i] < c[i - 1] || p[i] - p[i - 1] < c[i] - c[i - 1])
        {
            cout << "NO\n";
            return;
        }

    cout << "YES\n";
}
