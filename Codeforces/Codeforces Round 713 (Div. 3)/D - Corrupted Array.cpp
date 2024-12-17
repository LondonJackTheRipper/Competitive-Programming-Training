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
    map<ll, int> mp;
    ll sum = 0;
    for (int i = 0; i < n + 2; i++)
    {
        int x; cin >> x;
        sum += x;
        mp[x]++;
    }

    for (auto it : mp)
    {
        int val = it.first;
        if (mp[val] == 0) continue;

        mp[val]--;
        if (mp[sum - 2 * val] != 0)
        {
            mp[sum - 2 * val]--;

            for (auto iter : mp)
                for (int i = 0; i < iter.second; i++)
                    cout << iter.first << ' ';
            cout << '\n';

            return;
        }
        mp[val]++;
    }

    cout << -1 << '\n';
}
