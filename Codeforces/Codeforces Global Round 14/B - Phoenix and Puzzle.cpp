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

bool is_square(int n)
{
    int sq = sqrt(n);
    return (sq * sq == n);
}

void solve()
{
    int n; cin >> n;

    cout << ((n % 2 == 0 && is_square(n / 2)) || (n % 4 == 0 && is_square(n / 4)) ? "YES\n" : "NO\n");
}
