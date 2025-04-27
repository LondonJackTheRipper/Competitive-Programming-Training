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
int ask1(vector<int> vec)
{
    cout << "? 1 " << vec.size() << ' ';
    for (int x : vec)
        cout << x << ' ';
    cout << endl;
    int res; cin >> res;
    return res;
}

void ask2(int u)
{
    cout << "? 2 " << u << endl;
}

void rep(vector<int> res, int n)
{
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << endl;
}

int n;

void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
    }

    int parent = 1;
    int l = 2, r = n;
    while (l <= r)
    {
        int mid = l + r >> 1;

        vector<int> ask;
        for (int i = l; i <= mid; i++)
            ask.push_back(i);

        int res1 = ask1(ask);
        ask2(1);
        int res2 = ask1(ask);

        if (abs(res1 - res2) == 2 * (int)ask.size())
            l = mid + 1;
        else
        {
            parent = mid;
            r = mid - 1;
        }
    }

    vector<int> tmp(n + 1, 0);
    for (int i = 1; i <= n; i++)
        tmp[i] = ask1({i});
    vector<int> res(n + 1, 0);
    res[parent] = tmp[parent];
    for (int i = 1; i <= n; i++)
    {
        if (i == parent)
            continue;
        if (parent == 1)
            res[i] = tmp[i] - tmp[parent];
        else
            res[i] = tmp[i] - (i == 1 ?  tmp[parent] : tmp[1]);
    }

    rep(res, n);
}
