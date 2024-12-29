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

    int total = 0;
    int cur = 0;
    int res = 0;
    for (char c : s)
    {
        if (c == '0')
            cur++;
        else
        if (cur != 0)
        {
            total += cur;
            res += (cur + 1) / 2;
            cur = 0;
        }
    }
    if (cur != 0)
    {
        total += cur;
        res += (cur + 1) / 2;
    }

    cout << (int)s.length() - total + res << '\n';
}
