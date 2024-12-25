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
    int n, m; cin >> n;
    int pre1 = 0;
    int cur = 0;
    while (n--)
    {
        int x; cin >> x;
        cur += x;
        pre1 = max(pre1, cur);
    }
    cur = 0;
    int pre2 = 0;
    cin >> m;
    while (m--)
    {
        int x; cin >> x;
        cur += x;
        pre2 = max(pre2, cur);
    }

    cout << pre1 + pre2 << '\n';
}
