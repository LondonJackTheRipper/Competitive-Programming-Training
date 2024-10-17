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

    int t = 1;
    while (t--) solve();

    return 0;
}

// main program

string str = "qwertyuiopasdfghjkl;zxcvbnm,./";

void solve()
{
    char dir; cin >> dir;
    string s; cin >> s;

    for (char c : s)
    {
        int pos = str.find(c);
        cout << (dir == 'R' ? str[pos - 1] : str[pos + 1]);
    }
}
