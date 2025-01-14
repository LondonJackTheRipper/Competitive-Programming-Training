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
    string s; cin >> s;

    bool flag = false;
    for (char c : s)
        if ((c - '0') % 2 == 0)
            flag = true;
    if (!flag)
    {
        cout << "-1\n";
        return;
    }

    int idx;
    int last = s[(int)s.length() - 1] - '0';
    for (int i = 0; i < (int)s.length(); i++)
    {
        int num = s[i] - '0';
        if (num % 2 == 1)
            continue;

        if (num < last)
        {
            swap(s[i], s[(int)s.length() - 1]);
            cout << s << '\n';
            return;
        }
        idx = i;
    }

    swap(s[idx], s[(int)s.length() - 1]);
    cout << s << '\n';
}
