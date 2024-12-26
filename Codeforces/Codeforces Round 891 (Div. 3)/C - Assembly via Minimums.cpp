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
    for (int i = 0; i < n * (n - 1) / 2; i++)
    {
        int x; cin >> x;
        mp[x]++;
    }

    int cur = n - 1;
    vector<int> res;
    for (auto &it : mp)
        while (it.second > 0)
        {
            res.push_back(it.first);
            it.second -= cur;
            cur--;
        }
    while (res.size() < n) res.push_back(1e9);

    for (int x : res) cout << x << ' ';
    cout << '\n';
}
