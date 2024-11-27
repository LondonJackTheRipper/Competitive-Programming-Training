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
    string s; cin >> s;

    vector<int> pos;
    for (int i = 0; i < (int)s.length(); i++)
    {
        char c = s[i];
        if (c == 'L') continue;
        pos.push_back(i + 1);
    }

    if (pos.empty())
    {
        cout << (int)s.length() + 1 << '\n';
        return;
    }

    int res = max(pos[0], (int)s.length() + 1 - pos.back());
    for (int i = 1; i < (int)pos.size(); i++)
        res = max(res, pos[i] - pos[i - 1]);

    cout << res << '\n';
}
