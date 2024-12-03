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
    int n0, n1, n2; cin >> n0 >> n1 >> n2;

    if (n1 % 2 == 1)
    {
        for (int i = 0; i < n0; i++) cout << 0;
        for (int i = 0; i <= n1; i++) cout << (i % 2 == 0 ? 0 : 1);
        for (int i = 0; i < n2; i++) cout << 1;
        cout << '\n';
    } else
    {
        if (n1 == 0)
        {
            if (n0 != 0) for (int i = 0; i <= n0; i++) cout << 0;
            if (n2 != 0) for (int i = 0; i <= n2; i++) cout << 1;
            cout << '\n';
            return;
        }

        for (int i = 0; i < n0; i++) cout << 0;
        for (int i = 0; i < n1; i++) cout << (i % 2 == 0 ? 0 : 1);
        for (int i = 0; i < n2; i++) cout << 1; cout << 0;
        cout << '\n';
    }
}
