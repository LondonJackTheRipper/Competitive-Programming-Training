#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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

    int cnt = 0, idx;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if ((s[i] - '0') != 0)
            idx = i;
        else
            cnt++;
    }

    cout << n - idx - 1 + n - cnt - 1 << '\n';
}
