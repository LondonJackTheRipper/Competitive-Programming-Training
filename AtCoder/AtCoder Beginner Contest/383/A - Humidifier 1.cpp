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
    vector<pair<int, int>> w(n);
    for (pair<int, int> &p : w) cin >> p.first >> p.second;

    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (cur > 0) cur--;
        cur += w[i].second;
        if (i != n - 1) cur = max(0, cur - w[i + 1].first + w[i].first + 1);
    }

    cout << cur << '\n';
}
