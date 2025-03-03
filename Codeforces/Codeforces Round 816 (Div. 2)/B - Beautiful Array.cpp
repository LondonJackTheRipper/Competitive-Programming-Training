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
    int n, k, b; cin >> n >> k >> b;
    ll s; cin >> s;

    int frac = b / n, rem = b % n;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        a[i] = 1ll * frac * k;
        if (i <= rem)
            a[i] += k;
    }

    if (1ll * b * k <= s && s <= 1ll * b * k + 1ll * (k  - 1) * n)
    {
        s -= 1ll * b * k;
        for (int i = 1; i <= n; i++)
        {
            a[i] += min(k - 1ll, s);
            s -= min(k - 1ll, s);
            cout << a[i] << ' ';
        }
        cout << '\n';
    } else
        cout << -1 << '\n';
}
