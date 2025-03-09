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
    map<int, int> mp;
    vector<int> cnt(n + m + 1, 0);
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= m; i++)
    {
        int p, v; cin >> p >> v;

        cnt[a[p]] += i - mp[a[p]];
        mp[a[p]] = i - 1;

        a[p] = v;
        mp[a[p]] = i;
    }
    for (int i = 1; i <= n; i++)
        cnt[a[i]] += m - mp[a[i]] + 1;

    ll ans = 0;
    for (int i = 1; i <= n + m; i++)
    {
        if (cnt[i] == 0)
            continue;

        cnt[i] = m + 1 - cnt[i];
        ans += 1ll * m * (m + 1) / 2;
        if (cnt[i] > 1)
            ans -= 1ll * cnt[i] * (cnt[i] - 1 ) / 2;
    }

    cout << ans << '\n';
}
