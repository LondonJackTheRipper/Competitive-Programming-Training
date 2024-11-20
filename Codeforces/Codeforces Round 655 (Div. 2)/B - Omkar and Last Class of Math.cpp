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

int check(int x) // 1 +2^y
{
    x--;
    for (int i = 0; i < 30; i++)
        if ((1 << i) == x)
            return i;
    return -1;
}

void solve()
{
    int n; cin >> n;

    if (n % 2 == 0)
    {
        cout << n / 2 << ' ' << n / 2 << '\n';
        return;
    }

    ll mn = n - 1;
    int a = 1, b = n - 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i != 0) continue;

        ll lcm1 = LCM(i, n - i);
        if (lcm1 < mn)
        {
            mn = lcm1;
            a = i;
            b = n - i;
        }

        int tmp = n / i;
        ll lcm2 = LCM(tmp, n - tmp);
        if (lcm2 < mn)
        {
            mn = lcm2;
            a = tmp;
            b = n - tmp;
        }
    }

    cout << a << ' ' << b << '\n';
}
