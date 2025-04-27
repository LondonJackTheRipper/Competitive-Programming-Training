#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
    int n, m; cin >> n >> m;
    int a[m + 1];
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    sort(a + 1, a + m + 1);

    ll res = 0;
    for (int i = 1; i < n; i++)
    {
        int pos1 = lower_bound(a + 1, a + m + 1, i) - a; pos1 = m - pos1 + 1;
        int pos2 = lower_bound(a + 1, a + m + 1, n - i) - a; pos2 = m - pos2 + 1;

        res += 1ll * pos1 * pos2 - min(pos1, pos2);
    }

    cout << res << '\n';
}
