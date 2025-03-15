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
long long dist(int a, int b, int c, int d) { return 1ll * (a - c) * (a - c) + 1ll *  (b - d) * (b - d); }

void solve()
{
    int n, m; cin >> n >> m;
    map<int, int> mp;
    set<int> se;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].second;
        int x = p[i].first, r = p[i].second;
        int sub = 0, val = r;
        while (r > 0)
        {
            while (dist(x, 0, x + sub, val) > 1ll * p[i].second * p[i].second)
                val--;
            mp[x - sub] = max(mp[x - sub], val);
            mp[x + sub] = max(mp[x + sub], val);
            se.insert(x + sub);
            se.insert(x - sub);
            sub++;
            r--;
        }
        se.insert(x + sub);
        se.insert(x - sub);
    }

    ll ans = se.size();
    for (auto it : mp)
        ans += 2ll * it.second;

    cout << ans << '\n';
}
