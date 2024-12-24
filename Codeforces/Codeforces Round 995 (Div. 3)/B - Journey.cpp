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
    int n, a, b, c; cin >> n >> a >> b >> c;

    int res = n / (a + b + c);
    res *= 3;
    n %= (a + b + c);
    if (n != 0)
    {
        n -= a;
        res++;
        if (n <= 0) { cout << res << '\n'; return; }
        n -= b;
        res++;
        if (n <= 0) { cout << res << '\n'; return; }
        n -= c;
        res++;
    }

    cout << res << '\n';
}
