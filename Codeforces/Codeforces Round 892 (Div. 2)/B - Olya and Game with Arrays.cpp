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
    int n; cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int m; cin >> m;
        vector<int> tmp(m);
        for (int &x : tmp) cin >> x;
        sort(tmp.begin(), tmp.end());
        arr.push_back({tmp.front(), tmp[1]});
    }

    sort(arr.begin(), arr.end());
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + arr[i - 1].second;

    ll res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, arr[0].first + pre[i] + pre[n] - pre[i + 1]);

    cout << res << '\n';
}
