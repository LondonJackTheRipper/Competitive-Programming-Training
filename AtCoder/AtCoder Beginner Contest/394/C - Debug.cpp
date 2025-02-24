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
    reverse(s.begin(), s.end());

    int i = 1;
    while (i < (int)s.length())
        if (s[i] == 'W' && s[i - 1] == 'A')
        {
            int last;
            s[i - 1] = 'C';
            while (s[i] == 'W' && i < (int)s.length())
            {
                last = i;
                s[i] = 'C';
                i++;
            }
            s[last] = 'A';
        } else
            i++;

    reverse(s.begin(), s.end());
    cout << s;
}
