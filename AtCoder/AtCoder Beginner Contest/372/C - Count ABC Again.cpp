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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int cur = 0;
    for (int i = 0; i < n - 2; i++)
        cur += (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C');

    while (q--)
    {
        int x; cin >> x; x--;
        int add = 0;
        for (int i = max(0, x - 2); i <= min(n - 3, x); i++)
            add -= (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C');
        char c; cin >> c;
        s[x] = c;
        for (int i = max(0, x - 2); i <= min(n - 3, x); i++)
            add += (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C');

        cur += add;
        cout << cur << '\n';
    }
}