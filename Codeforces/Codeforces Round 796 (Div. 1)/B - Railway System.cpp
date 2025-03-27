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

    solve();

    return 0;
}

// main program
int ask(vector<int> s)
{
    cout << "? ";
    for (int x : s)
        cout << x;
    cout << endl;
    int res; cin >> res;
    return res;
}

void rep(int ans)
{
    cout << "! " << ans << endl;
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges;
    vector<int> tmp(m, 0);
    for (int i = 1; i <= m; i++)
    {
        tmp[i - 1] = 1;
        edges.push_back({ask(tmp), i});
        tmp[i - 1] = 0;
    }

    int ans = 0;
    sort(edges.begin(), edges.end());
    for (pair<int, int> it : edges)
    {
        tmp[it.second - 1] = 1;
        int res = ask(tmp);

        if (res == ans + it.first)
            ans = res;
        else
            tmp[it.second - 1] = 0;
    }

    rep(ans);
}
