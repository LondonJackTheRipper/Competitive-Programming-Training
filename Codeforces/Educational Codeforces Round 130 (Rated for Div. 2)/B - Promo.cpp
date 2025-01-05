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

void solve()
{
    int n, q; cin >> n >> q;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];

    while (q--)
    {
        int x, y; cin >> x >> y;

        int sub = x - y;

        cout << pre[n] - pre[n - x] - pre[n] + pre[n - sub] << '\n';
    }
}
