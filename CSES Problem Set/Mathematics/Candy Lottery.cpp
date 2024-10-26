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
long double power(long double a, int b)
{
    long double res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

void solve()
{
    int n, k; cin >> n >> k;

    long double res = 0;
    for (int i = 1; i <= k; i++)
        res += i * (power((long double)(i) / k, n) - power((long double)(i - 1) / k, n));

    cout << fixed << setprecision(6) << res << '\n';
}
