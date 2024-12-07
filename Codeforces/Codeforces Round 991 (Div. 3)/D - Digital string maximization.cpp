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
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        int cur = s[i] - '0';
        int num = cur, idx = -1;
        for (int j = i + 1; j < min(n, i + 10); j++)
        {
            int nu = s[j] - '0';
            int ans = nu - j + i;
            if (ans > num)
            {
                num = ans;
                idx = j;
            }
        }
        if (idx != -1)
        {
            for (int j = idx; j > i; j--)
                s[j] = s[j - 1];
            s[i] = char('0' + num);
        }
    }

    cout << s << '\n';
}
