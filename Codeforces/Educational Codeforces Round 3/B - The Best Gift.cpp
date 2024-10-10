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

    int t = 1;
    while (t--) solve();

    return 0;
}

// main program

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        cnt[x]++;
    }

    ll res = 0;
    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
            res += 1ll * cnt[i] * cnt[j];

    cout << res << '\n';
}
