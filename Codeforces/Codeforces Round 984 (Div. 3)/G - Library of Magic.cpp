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
ll ask(ll l, ll r)
{
    if (l > r) return 0;
    cout << "xor " << l << ' ' << r << endl;
    ll res; cin >> res;
    return res;
}

void rep(ll a, ll b, ll c)
{
    cout << "ans " << a << ' ' << b << ' ' << c << endl;
}

ll n, num1, num2;

ll solve_range(ll l, ll r, int num)
{
    if (l > r) return 0;
    if (r > n) r = n;

    ll res = ask(l, r);

    if (num > 1 && l <= num1 && num1 <= r) res ^= num1;
    if (num > 2 && l <= num2 && num2 <= r) res ^= num2;
    return res;
}

void solve()
{
    cin >> n;
    num1 = num2 = 0;

    int highest;
    for (int i = 59; i >= 0; i--)
        if (n >> i & 1)
        {
            highest = i;
            break;
        }
    ll st = (1ll << highest);

    for (ll i = st; i > 0; (i >>= 1ll))
    {
        ll tmp = solve_range(num1 | i, num1 | (2 * i - 1), 1);
        if (tmp != 0)
            num1 |= i;
    }

    for (ll i = st; i > 0; (i >>= 1ll))
    {
        ll tmp = solve_range(num2 | i, num2 | (2 * i - 1), 2);
        if (tmp != 0)
            num2 |= i;
    }

    rep(num1, num2, solve_range(1, n, 3));
}
