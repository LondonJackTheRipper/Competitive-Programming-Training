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
const int maxn = 131080;

int n;
int res = 1e9;
int convert[maxn][26];
string s;

int con(int l, int r, int c) { return convert[r][c] - convert[l - 1][c]; }

void gen(int l, int r, int ans = 0, int cur = 0)
{
    if (l == r)
    {
        res = min(res, ans + (s[l] != char(cur + 'a')));
        return;
    }

    int mid = l + r >> 1;
    gen(l, mid, ans + con(mid + 1, r, cur), cur + 1);
    gen(mid + 1, r, ans + con(l, mid, cur), cur + 1);
}

void solve()
{
    cin >> n >> s;

    s = " " + s;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            convert[i][j] = convert[i - 1][j] + (s[i] != char('a' + j));

    res = 1e9;
    gen(1, n);

    cout << res << '\n';
}
