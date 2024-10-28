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

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// main program

void solve()
{
    int n; cin >> n;
    if (n % 2 == 0)
    {
        for (int i = 0; i < n - 2; i++) cout << 3;
        cout << 66 << '\n';
        return;
    }
    if (n <= 3)
    {
        cout << -1 << '\n';
        return;
    }

    string res = "";
    for (int i = 0; i < n; i++) res.push_back('3');
    res[n - 1] = res[n - 2] = res[n - 4] = '6';
    cout << res << '\n';
}
