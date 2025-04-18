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
    vector<int> v(3);
    for (int &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    
    if (v[1] == 0)
        cout << 0 << '\n';
    else
    if (v[0] == 0)
        cout << v[1] << '\n';
    else
        cout << ((v[0] + v[1]) % 2 == 0 && (v[0] % 2 == 1) ? v[0] + v[1] - 1 : v[0] + v[1]) << '\n';
}
