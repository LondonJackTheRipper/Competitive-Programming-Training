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
    int n; cin >> n;
    int b[2 * n];
    for (int i = 0; i < 2 * n; i++)
        cin >> b[i];
    vector<ll> ans(2 * n + 1, 0);
    sort(b, b + 2 * n, greater<int>());
    ans[0] = b[0];
    ll res = b[0];
    for (int i = 1; i < 2 * n - 2; i += 2)
    {
        ans[i] = b[i + 1];
        ans[i + 1] = b[i];
        res += b[i] - b[i + 1];
    }
    res += b[2 * n - 1];
    ans[2 * n - 1] = res;
    ans[2 * n] = b[2 * n - 1];

    for (int i = 0; i < 2 * n + 1; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
