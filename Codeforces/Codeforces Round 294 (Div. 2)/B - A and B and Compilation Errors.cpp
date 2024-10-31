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
    map<int, int> mp;
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x]++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x; cin >> x;
        mp[x]++;
    }
    for (auto &it : mp)
        if ((it.second % 2) != 0)
        {
            cout << it.first << '\n';
            it.second += 2;
            break;
        }
    for (int i = 0; i < n - 2; i++)
    {
        int x; cin >> x;
        mp[x]++;
    }
    for (auto it : mp)
        if ((it.second % 3) != 0)
        {
            cout << it.first << '\n';
            break;
        }
}
