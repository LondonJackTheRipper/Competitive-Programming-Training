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
const int lim = 1e9;

void solve()
{
    int n, m; cin >> n >> m;

    ll res = 1, cur = 1;
    for (int i = 1; i <= m; i++)
    {
        cur *= n;
        if (cur > lim || res + cur > lim)
        {
            cout << "inf\n";
            return;
        }
        res += cur;
    }

    cout << res << '\n';
}
