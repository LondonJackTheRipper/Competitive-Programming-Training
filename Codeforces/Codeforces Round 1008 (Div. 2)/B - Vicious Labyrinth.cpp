#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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

    if (n == 2)
        cout << "2 1" << '\n';
    else
    {
        if (k % 2 == 0)
        {
            for (int i = 0; i < n; i++)
                cout << (i == n - 2 ? n : n - 1) << ' ';
        } else
        {
            for (int i = 0; i < n; i++)
                cout << (i == n - 1 ? n - 1 : n) << ' ';
        }
        cout << '\n';
    }
}
