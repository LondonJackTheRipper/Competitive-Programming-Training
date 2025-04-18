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
    int n, k; cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        int b, c; cin >> b >> c;
        mp[b] += c;
    }

    vector<int> tmp;
    for (auto it : mp)
        tmp.push_back(it.second);
    sort(tmp.begin(), tmp.end(), greater<int>());

    int res = 0;
    for (int i = 0; i < min(n, (int)tmp.size()); i++)
        res += tmp[i];

    cout << res << '\n';
}
