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
const int maxn = 2e5 + 9;

string s;
int pre[maxn][26], suff[maxn][26];

void solve()
{
    cin >> s;
    int n = s.length();
    s = " " + s;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            pre[i][j] = pre[i - 1][j] + ((s[i] - 'A') == j);
    for (int i = n; i > 0; i--)
        for (int j = 0; j < 26; j++)
            suff[i][j] = suff[i + 1][j] + ((s[i] - 'A') == j);

    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        ll tmp = 0;
        for (int j = 0; j < 26; j++)
            tmp += 1ll * pre[i - 1][j] * suff[i + 1][j];
        res += tmp;
    }
    cout << res << '\n';
}
