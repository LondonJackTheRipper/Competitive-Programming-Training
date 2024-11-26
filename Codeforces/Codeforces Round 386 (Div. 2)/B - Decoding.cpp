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
    int n; cin >> n;
    string s; cin >> s;

    int mid = (n + 1) / 2 - 1;
    vector<char> res(n);
    for (int i = 0; i < n; i++)
        res[i % 2 == 0 ? mid - (i / 2) : mid + ((i + 1) / 2)] = s[i];

    if (n % 2 == 1) 
    for (int i = n - 1; i >= 0; i--) cout << res[i]; else
    for (int i = 0; i < n; i++) cout << res[i]; 
}
