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
pair<int, int> mn_mx(ll a)
{
    int mn = 10, mx = 0;
    while (a)
    {
        mn = min(1ll * mn, a % 10);
        mx = max(1ll * mx, a % 10);
        a /= 10;
    }
    return {mn, mx};
}

void solve()
{
    ll a, k; cin >> a >> k; k--;

    pair<int, int> tmp = mn_mx(a);
    while (k > 0 && tmp.first != 0 && tmp.second != 0)
    {
        a += tmp.first * tmp.second;
        tmp = mn_mx(a);
        k--;
    }

    cout << a << '\n';
}
