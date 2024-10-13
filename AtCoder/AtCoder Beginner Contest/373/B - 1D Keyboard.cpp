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
    unordered_map<char, int> mp;
    for (int i = 1; i <= 26; i++)
    {
        char c; cin >> c;
        mp[c] = i;
    }

    int res = 0;
    int prev = mp['A'];
    for (char c = 'A'; c <= 'Z'; c++)
    {
        res += abs(prev - mp[c]);
        prev = mp[c];
    }
    cout << res << '\n';
}