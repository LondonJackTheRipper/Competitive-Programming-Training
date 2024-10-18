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
    int n, a, b; cin >> n >> a >> b;

    string res = "";
    for (int i = 0; i < b; i++)
        res.push_back(char(i + 'a'));
    while (res.length() < a) res.push_back(char('a'));
    for (int i = a; i < n; i++)
        res.push_back(res[i - a]);

    cout << res << '\n';
}
