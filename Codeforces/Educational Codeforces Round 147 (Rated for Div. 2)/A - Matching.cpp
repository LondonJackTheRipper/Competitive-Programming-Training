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
    if (s[0] == '0')
    {
        cout << 0 << '\n';
        return;
    }

    int res = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '?') continue;
        res *= (i == 0 ? 9 : 10);
    }

    cout << res << '\n';
}
