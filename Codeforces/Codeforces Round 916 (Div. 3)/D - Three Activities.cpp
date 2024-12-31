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
    vector<int> a(n);
    vector<pair<int, int>> b(n), c(n);
    for (int &x : a) cin >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].first;
        b[i].second = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(b.begin(), b.end(), greater<pair<int, int>>());
    sort(c.begin(), c.end(), greater<pair<int, int>>());

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, v = -1;
        for (int j = 0; j < 3; j++)
            if (u == -1 && b[j].second != i)
                u = j;
        for (int j = 0; j < 3; j++)
            if (u != -1 && v == -1 && c[j].second != i && c[j].second != b[u].second)
                v = j;
        res = max(res, a[i] + b[u].first + c[v].first);
        u = v = -1;
        for (int j = 0; j < 3; j++)
            if (u == -1 && c[j].second != i)
                u = j;
        for (int j = 0; j < 3; j++)
            if (u != -1 && v == -1 && b[j].second != i && b[j].second != c[u].second)
                v = j;
        res = max(res, a[i] + c[u].first + b[v].first);
    }

    cout << res << '\n';
}
