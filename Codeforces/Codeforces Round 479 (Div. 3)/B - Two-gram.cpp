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

    int t = 1;
    while (t--) solve();

    return 0;
}

// main program

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    map<string, int> mp;
    for (int i = 0; i < s.length() - 1; i++)
        mp[s.substr(i, 2)]++;

    string cur = s.substr(0, 2);
    for (auto it : mp)
        if (it.second > mp[cur])
            cur = it.first;
    cout << cur << '\n';
}
