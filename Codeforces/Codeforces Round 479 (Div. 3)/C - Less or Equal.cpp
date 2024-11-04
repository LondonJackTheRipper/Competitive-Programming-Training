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
    int n, k; cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x]++;
    }

    if (k == 0)
    {
        cout << (mp.begin()->first == 1 ? -1 : 1) << '\n';
        return;
    }

    vector<pair<int, int>> proc;
    for (auto it : mp)
        proc.push_back({it.first, it.second});

    int prefix = 0;
    for (pair<int, int> p : proc)
    {
        prefix += p.second;
        if (prefix == k)
        {
            cout << p.first << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}
