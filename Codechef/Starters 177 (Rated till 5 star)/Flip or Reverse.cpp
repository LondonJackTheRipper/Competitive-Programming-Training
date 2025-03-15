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

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// main program

void solve()
{
    int n; cin >> n;
    string a, b; cin >> a >> b;
    vector<tuple<int, int, int>> ans;
    for (int i = 0; i < n - 1; i += 2)
    {
        string s = a.substr(i, 2); reverse(s.begin(), s.end());
        if (s == b.substr(i, 2))
        {
            ans.push_back({2, i + 1, i + 2});
            continue;
        }
        s = a.substr(i, 2); for (char &c : s) if (c == '1') c = '0'; else c = '1';
        if (s == b.substr(i, 2))
        {
            ans.push_back({1, i + 1, i + 2});
            continue;
        }
        s = a.substr(i, 2); if (s[0] == '1') s[0] = '0'; else s[0] = '1';
        if (s == b.substr(i, 2))
        {
            ans.push_back({1, i + 1, i + 1});
            continue;
        }
        s = a.substr(i, 2); if (s[1] == '1') s[1] = '0'; else s[1] = '1';
        if (s == b.substr(i, 2))
        {
            ans.push_back({1, i + 2, i + 2});
            continue;
        }
    }
    if (n % 2 == 1)
    {
        if (a.back() != b.back())
            ans.push_back({1, n, n});
    }
    
    cout << ans.size() << '\n';
    for (tuple<int, int, int> it : ans)
        cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << '\n';
}
