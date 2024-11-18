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

    int cur = 0;
    vector<int> a;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '|')
        {
            a.push_back(cur);
            cur = 0;
        } else
            cur++;
    }

    for (int x : a) cout << x << ' '; cout << '\n';
}
