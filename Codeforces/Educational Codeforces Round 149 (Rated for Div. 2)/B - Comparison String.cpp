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

    int mx = 0, cur = 0;
    char cur_c = '#';
    for (char c : s)
        if (c == cur_c)
            cur++;
        else
        {
            mx = max(mx, cur);
            cur = 1;
            cur_c = c;
        }
    mx = max(mx, cur);

    cout << mx + 1 << '\n';
}
