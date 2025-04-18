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

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// main program

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    
    int i;
    int boys = 0, girls = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'B')
            boys++;
        else
            girls++;
            
        if (boys > 2 * girls)
            break;
    }
    
    cout << (i + 1 > n ? i : i + 1) << '\n';
}
