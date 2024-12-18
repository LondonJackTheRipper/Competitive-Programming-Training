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
    string s; cin >> s;
    int n = (int)s.length();

    if (n % 2 == 1)
    {
        cout << "NO" << '\n';
        return;
    }

    int cnt = 0;
    for (char &c : s)
    {
        if (c != '?') continue;

        c = (cnt < (n - 2) / 2 ? '(' : ')');
        cnt++;
    }

    int pre = 0;
    for (char c : s)
    {
        pre += (c == '(' ? 1 : -1);

        if (pre < 0)
        {
            cout << "NO\n";
            return;
        }
    }
    if (pre != 0)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}
