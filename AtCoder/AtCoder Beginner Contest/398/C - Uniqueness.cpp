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
    map<int, int> mp, label;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x]++;
        label[x] = i + 1;
    }

    int res = -1;
    for (auto it : mp)
        if (it.second == 1)
            res = max(res, it.first);

    cout << (res == -1 ? -1 : label[res]) << '\n';
}
