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
int GCD(int a, int b) { return (b == 0 ? a : GCD(b, a % b)); }
ll LCM(int a, int b) { return 1ll * a / GCD(a, b) * b; }

void solve()
{
    int n, x, y; cin >> n >> x >> y;

    int num_x = n / x, num_y = n / y;
    ll lcm = LCM(x, y);
    int sub = n / lcm;
    num_x -= sub;
    num_y -= sub;

    cout << 1ll * (2 * n - num_x + 1) * num_x / 2 -  1ll * (num_y + 1) * num_y / 2 << '\n';
}
