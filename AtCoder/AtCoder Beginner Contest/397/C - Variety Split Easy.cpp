#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
    int n; cin >> n;
    int a[n + 1];
    vector<int> pre(n + 1, 0);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + (mp[a[i]] == 0);
        mp[a[i]] = 1;
    }
    mp.clear();
    vector<int> suff(n + 2, 0);
    for (int i = n; i > 0; i--)
    {
        suff[i] = suff[i + 1] + (mp[a[i]] == 0);
        mp[a[i]] = 1;
    }

    int res = 0;
    for (int i = 1; i < n; i++)
        res = max(res, pre[i] + suff[i + 1]);

    cout << res << '\n';
}
