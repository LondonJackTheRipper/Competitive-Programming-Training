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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> lines(m);
    for (pair<int, int> &it : lines)
    {
        cin >> it.first >> it.second;
        if (it.first > it.second)
            swap(it.first, it.second);
    }

    sort(lines.begin(), lines.end());
    map<int, int> mp;
    ll res = 0;
    for (pair<int, int> it : lines)
    {
        int sum = it.first + it.second;

        if (sum > n)
            sum -= n;
        res += mp[sum];
        mp[sum]++;
    }

    cout << 1ll * m * (m - 1) / 2 - res << '\n';
}
