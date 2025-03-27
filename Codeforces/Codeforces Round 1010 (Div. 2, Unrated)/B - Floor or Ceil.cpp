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
    int x, n, m; cin >> x >> n >> m;

    int prev = x;
    int nn = n, mm = m, xx = x;
    while (m > 0 && (x + 1) / 2 != prev)
    {
        x = (x + 1) / 2;
        prev = x;
        m--;
    }
    while (n > 0 && x / 2 != prev)
    {
        x /= 2;
        prev = x;
        n--;
    }
    cout << x << ' ';
    prev = xx;
    while (nn > 0 && xx / 2 != prev)
    {
        xx /= 2;
        prev = xx;
        nn--;
    }
    while (mm > 0 && (xx + 1) / 2 != prev)
    {
        xx = (xx + 1) / 2;
        prev = xx;
        mm--;
    }
    cout << xx << '\n';
}
