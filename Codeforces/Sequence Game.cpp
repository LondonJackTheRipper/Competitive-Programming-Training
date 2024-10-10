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
    int n; cin >> n;
    vector<int> b(n);
    for (int &x : b) cin >> x;

    vector<int> res;
    res.push_back(b[0]);
    for (int i = 1; i < n; i++)
    {
        if (b[i] >= res.back())
            res.push_back(b[i]);
        else
        {
            res.push_back(1);
            res.push_back(b[i]);
        }
    }

    cout << res.size() << '\n';
    for (int x : res) cout << x << ' '; cout << '\n';
}
