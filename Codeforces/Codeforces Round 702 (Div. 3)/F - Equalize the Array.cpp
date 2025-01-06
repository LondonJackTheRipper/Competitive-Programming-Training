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
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x]++;
    }

    vector<int> val;
    for (auto it : mp)
        val.push_back(it.second);
    sort(val.begin(), val.end());
    n = (int)val.size();
    vector<int> pre(n);
    pre[0] = val[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + val[i];

    int res = 1e9;
    for (int C = val[0]; C <= val.back(); C++)
    {
        int tmp = 0;
        int pos1 = lower_bound(val.begin(), val.end(), C) - val.begin();
        int pos2 = upper_bound(val.begin(), val.end(), C) - val.begin();

        if (pos1 != 0)
            tmp = pre[pos1 - 1];
        tmp += (pre[n - 1] - (pos2 == 0 ? 0 : pre[pos2 - 1])) - (n - pos2) * C;

        res = min(res, tmp);
    }

    cout << res << '\n';
}
