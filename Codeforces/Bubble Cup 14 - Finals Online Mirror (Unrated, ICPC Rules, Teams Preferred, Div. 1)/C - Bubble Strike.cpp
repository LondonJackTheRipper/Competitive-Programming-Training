#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
long double C23(int x, int n)
{
    if (x < 2) return 0;
    return (3.0 * x * (x - 1)) / (1.0 * n * (n - 1) * (n - 2));
}

long double C33(int x, int n)
{
    if (x < 3) return 0;
    return (1.0 * x * (x - 1) * (x - 2)) / (1.0 * n * (n - 1) * (n - 2));
}

void solve()
{
    int n;
    long double p;
    cin >> n >> p;

    for (int x = 0; x <= n; x++)
    {
        long double prob = C23(x, n) * (n - x) + C23(n - x, n) * 0.5 * x + C33(x, n);
        if (prob >= p)
        {
            cout << x << '\n';
            return;
        }
    }
}
