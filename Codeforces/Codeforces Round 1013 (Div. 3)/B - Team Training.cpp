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
    ll x; cin >> x;
    ll a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll ans1 = 0;
    ll cur = 1e18;
    int cnt = 0;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        cur = min(cur, a[i]);
        cnt++;

        if (cur * cnt >= x)
        {
            ans1++;
            cur = 1e18;
            cnt = 0;
        }
    }
    cur = 1e18;
    cnt = 0;
    ll ans2 = 0;
    sort(a + 1, a + n + 1, greater<ll>());
    for (int i = 1; i <= n; i++)
    {
        cur = min(cur, a[i]);
        cnt++;

        if (cur * cnt >= x)
        {
            ans2++;
            cur = 1e18;
            cnt = 0;
        }
    }

    cout << max(ans1, ans2) << '\n';
}
