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
    string a, b; cin >> a >> b;

    int res = (int)a.length() + (int)b.length();
    for (int i = 0; i < (int)a.length(); i++)
        for (int j = i; j < (int)a.length(); j++)
            for (int u = 0; u < (int)b.length(); u++)
                for (int v = 0; v < (int)b.length(); v++)
                    if (a.substr(i, j - i + 1) == b.substr(u, v - u + 1))
                        res = min(res, (int)a.length() - (j - i + 1) + (int)b.length() - (v - u + 1));

    cout << res << '\n';
}
