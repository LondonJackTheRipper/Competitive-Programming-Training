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
    int n, d; cin >> n >> d;
    vector<pair<int, int>> snakes(n);
    for (pair<int, int>& it : snakes)
        cin >> it.first >> it.second;

    for (int k = 1; k <= d; k++)
    {
        int res = 0;
        for (pair<int, int> it : snakes)
            res = max(res, it.first * (it.second + k));
        cout << res << '\n';
    }
}
