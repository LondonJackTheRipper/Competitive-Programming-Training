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
int ask(int a, int b)
{
    cout << "? " << a << ' ' << b << endl;
    int res; cin >> res;
    return res;
}

void rep(vector<pair<int, int>> res)
{
    cout << "! ";
    for (auto it : res)
        cout << it.first << ' ' << it.second << ' ';
    cout << endl;
}

void solve()
{
    int n; cin >> n;

    vector<pair<int, int>> res;
    for (int i = 2; i <= n; i++)
    {
        int st = 1, ans;
        while ((ans = ask(i, st)) != i)
            st = ans;
        res.push_back({st, i});
    }

    rep(res);
}
