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
ll XOR(ll pos)
{
    ll rem = pos % 4;
    if (rem == 0) return pos;
    if (rem == 1) return 1;
    if (rem == 2) return pos + 1;
    return 0;
}

ll XOR_range(ll l, ll r) { return (XOR(r) ^ XOR(l - 1)); }

void solve()
{
    ll l, r; cin >> l >> r;
    int i, k; cin >> i >> k;

    // l <= 2 ^ i * x + k <= r
    ll LEFT = (l - k + (1 << i) - 1) >> i;
    ll RIGHT = (r - k) >> i;

    ll res = XOR_range(l, r);
    if ((RIGHT - LEFT + 1) % 2 == 1)
        res ^= k;
    res ^= (XOR_range(LEFT, RIGHT) << i);

    cout << res << '\n';
}
