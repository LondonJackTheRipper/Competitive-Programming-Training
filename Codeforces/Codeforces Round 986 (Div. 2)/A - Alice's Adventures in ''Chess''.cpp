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
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    int x = 0, y = 0;
    for (int i = 0; i < 100; i++)
    {
        for (char c : s)
        {
            if (c == 'N') y++; else
            if (c == 'E') x++; else
            if (c == 'S') y--; else
                x--;

            if (x == a && y == b)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}
