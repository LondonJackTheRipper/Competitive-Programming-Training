#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
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
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> proc;
    vector<int> tmp;
    for (int i = 2; i <= n; i += 2)
    {
        if (a[i] != a[i - 1])
        {
            if (!tmp.empty())
            {
               proc.push_back(tmp);
               tmp.clear();
            }
        } else
        {
            tmp.push_back(a[i - 1]);
        }
    }
    if (!tmp.empty())
        proc.push_back(tmp);
    tmp.clear();
    for (int i = 3; i <= n; i += 2)
    {
        if (a[i] != a[i - 1])
        {
            if (!tmp.empty())
            {
               proc.push_back(tmp);
               tmp.clear();
            }
        } else
            tmp.push_back(a[i - 1]);
    }
    if (!tmp.empty())
        proc.push_back(tmp);

    int res = 0;
    for (vector<int> s : proc)
    {
        map<int, int> mp;
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            while (mp[s[i]] > 0)
                mp[s[j++]]--;
            mp[s[i]]++;
            res = max(res, 2 * (i - j + 1));
        }
    }

    cout << res << '\n';
}
