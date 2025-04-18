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

    solve();

    return 0;
}

// main program

void solve()
{
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();

    vector<int> mn(27, 1e9), mx(27, 0);
    for (int i = 1; i < n; i++)
        mn[s[i] - 'a'] = min(mn[s[i] - 'a'], i + 1);
    for (int i = 0; i < m - 1; i++)
        mx[t[i] - 'a'] = max(mx[t[i] - 'a'], i + 1);

    int l = 1e8, r = 1e8;
    for (int i = 0; i < 26; i++)
        if (mn[i] != (int)1e9 && mx[i] != 0 && mn[i] + m + 1 - mx[i] < l + r)
        {
            l = mn[i];
            r = m + 1 - mx[i];
        }

    if (l == (int)1e8)
        cout << -1 << '\n';
    else
    {
        cout << s.substr(0, l);
        cout << t.substr(m + 1 - r, r - 1);
        cout << '\n';
    }
}
