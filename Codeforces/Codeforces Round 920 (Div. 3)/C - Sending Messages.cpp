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
    int n, f, a, b; cin >> n >> f >> a >> b;
    int m[n + 1];
    m[0] = 0;
    for (int i = 1; i <= n; i++) cin >> m[i];

    ll total = 0;
    for (int i = 1; i <= n; i++)
        total += min(1ll * (m[i] - m[i - 1]) * a, 1ll * b);

    cout << (total >= f ? "NO\n" : "YES\n");
}
