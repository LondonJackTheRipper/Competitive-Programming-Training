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
    int n, m;
    cin >> n >> m;
    vector<int> friends(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        if (u > v)
            swap(u, v);
        friends[v] = max(friends[v], u);
    }

    ll res = 0;
    int mx = 1;
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, friends[i] + 1);
        res += i - mx + 1;
    }

    cout << res << '\n';
}
