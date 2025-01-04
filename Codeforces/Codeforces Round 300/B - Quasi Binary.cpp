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

    int mx = 0;
    for (char c : s)
        mx = max(mx, c - '0');

    vector<int> res(mx, 0);
    for (int i = (int)s.length() - 1; i >= 0; i--)
    {
        int num = s[i] - '0';
        int add = 1;
        for (int j = i; j < (int)s.length() - 1; j++)
            add *= 10;
        for (int j = 0; j < num; j++)
            res[j] += add;
    }

    cout << mx << '\n';
    for (int i = mx - 1; i >= 0; i--)
        cout << res[i] << ' ';
    cout << '\n';
}
