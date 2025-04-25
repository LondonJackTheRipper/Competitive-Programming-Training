#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
    int n, x; cin >> n >> x;

    vector<int> res;
    for (int i = 0; i < x; i++)
        res.push_back(i);
    for (int i = x + 1; i < n; i++)
        res.push_back(i);
    if (x != n)
        res.push_back(x);

    for (int x : res)
        cout << x << ' ';
    cout << '\n';
}
