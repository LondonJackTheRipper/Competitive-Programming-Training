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
    int n; cin >> n;
    string s; cin >> s;

    int res = n - 1;
    char cur = '#';
    int num = 0;
    for (char c : s)
    {
        if (c == cur)
            num++;
        else
        {
            if (num != 0)
                res -= max(num - 2, 0);

            num = 1;
        }

        cur = c;
    }
    res -= max(num - 2, 0);
    for (int i = 0; i < n; i++)
        if (i > 0 && i < n - 1 && s[i - 1] == s[i + 1] && s[i] != s[i - 1])
            res--;

    cout << res << '\n';
}
