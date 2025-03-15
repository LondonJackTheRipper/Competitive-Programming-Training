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

void solve()
{
    string s; cin >> s;

    int cur = s.length();
    vector<int> cc = {'i', 'o'};
    int turns = 0;
    for (char c : s)
    {
        if (c != cc[turns])
        {
            cur++;
            turns ^= 1;
        }
        turns ^= 1;
    }

    cout << cur - (int)s.length() + (cur % 2) << '\n';
}
