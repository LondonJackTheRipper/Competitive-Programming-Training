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
    string s, t; cin >> s >> t;

    if (s == t)
    {
        cout << 0 << '\n';
        return;
    }
    int res = min(s.length(), t.length()) + (s.length() != t.length());
    for (int i = 0; i < min(s.length(), t.length()); i++)
        if (s[i] != t[i])
            res = min(res, i + 1);
    cout << res << '\n';
}