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

    int pos = 0;
    int pos_0 = -1;
    bool one = false;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if (one == false && c == '0') pos_0++;
        if (c == '1') one = true; else
        if (one == true) pos = i;
    }

    if (pos == 0)
    {
        cout << s << '\n';
        return;
    }

    for (int i = 0; i <= pos_0; i++) cout << s[i];
    for (; pos < n; pos++)
        cout << s[pos];
    cout << '\n';
}
