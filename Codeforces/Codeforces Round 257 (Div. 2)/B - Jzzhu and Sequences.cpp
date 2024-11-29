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
const int mod = 1e9 + 7;

int MOD(int x)
{
    while (x < 0)
        x += mod;
    return x % mod;
}

void solve()
{
    vector<int> f(4, 0);
    cin >> f[1] >> f[2];
    f[3] = f[2] - f[1];
    int n; cin >> n;

    cout << (n <= 3 ? MOD(f[n]) : MOD((((n - 1) / 3) % 2 == 1 ? -1 : 1) * f[n % 3 == 0 ? 3 : n % 3])) << '\n';
}
