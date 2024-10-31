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

    int res = 1e9, cur1 = 0, cur2 = 0;
    for (int i = -1; i < (int)s.length(); i++)
    {
        int ans1 = 0, ans2 = 0;
        for (int j = i + 1; j < s.length(); j++)
        {
            ans1 += (s[j] == '1');
            ans2 += (s[j] == '0');
        }

        if (i != -1)
        {
            cur1 += (s[i] == '1');
            cur2 += (s[i] == '0');
        }

        res = min({res, cur1 + ans2, cur2 + ans1});
    }

    cout << res << '\n';
}
