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

    vector<int> cnt;
    for (auto it : mp)
    {
        if (it.second >= 4)
        {
            cout << it.first << ' ' << it.first << ' ' << it.first << ' ' << it.first << '\n';
            return;
        }
        if (it.second >= 2)
            cnt.push_back(it.first);
    }
    if ((int)cnt.size() > 1)
    {
        cout << cnt[0] << ' ' << cnt[0] << ' ' << cnt[1] << ' ' << cnt[1] << '\n';
        return;
    } else
    if ((int)cnt.size() == 1)
    {
        vector<int> proc;
        for (auto it : mp)
        {
            int lim = it.second;
            if (it.first == cnt[0])
                lim -= 2;
            while (lim > 0)
            {
                proc.push_back(it.first);
                lim--;
            }
        }
        sort(proc.begin(), proc.end());
        for (int i = 1; i < (int)proc.size(); i++)
            if (proc[i] - proc[i - 1] < 2 * cnt[0])
            {
                cout << cnt[0] << ' ' << cnt[0] << ' ' << proc[i] << ' ' << proc[i - 1] << '\n';
                return;
            }
    }
    cout << -1 << '\n';
}
