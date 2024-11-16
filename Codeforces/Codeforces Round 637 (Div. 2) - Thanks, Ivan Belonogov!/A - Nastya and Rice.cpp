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
    int n, a, b, c, d; cin >> n >> a >> b >> c >> d;

    int total_least = n * (a - b);

    if (total_least > c + d)
        cout << "No\n";
    else
    if (total_least >= c - d)
        cout << "Yes\n";
    else
        cout << (2 * n * b >= c - d - total_least ? "Yes\n" : "No\n");
}
