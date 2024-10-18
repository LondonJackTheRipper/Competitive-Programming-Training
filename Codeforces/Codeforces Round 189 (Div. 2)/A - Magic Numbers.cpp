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
    string s; cin >> s;

    vector<int> mark(s.length() + 1, 0);
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (mark[i] == 1 || s[i] != '4') continue;

        if (i != 0 && mark[i - 1] == 0 && s[i - 1] == '1')
            mark[i] = mark[i - 1] = 1;
        if (i > 1 && mark[i - 1] == 0 && mark[i - 2] == 0 && s[i - 1] == '4' && s[i - 2] == '1')
            mark[i] = mark[i - 1] = mark[i - 2] = 1;
    }

    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '4' && s[i] != '1') continue;
        if (mark[i] == 0 && s[i] == '1') mark[i] = 1;
        res += mark[i];
    }

    cout << (res == s.length() ? "YES\n" : "NO\n");
}
