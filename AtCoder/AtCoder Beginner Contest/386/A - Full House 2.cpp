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
    for (int i = 0; i < 4; i++)
    {
        int x; cin >> x;
        mp[x]++;
    }

    if (mp.size() != 2)
    {
        cout << "No\n";
        return;
    }
    for (auto it : mp)
        if (it.second == 4)
        {
            cout << "No\n";
            return;
        }

    cout << "Yes\n";
}
