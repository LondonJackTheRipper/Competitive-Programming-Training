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
    int n, m; cin >> n >> m;
    int a[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c; cin >> c;
            a[i][j] = (c - '0');
        }

    ll res = 0;
    for (int layer = 1; layer <= min(n, m) / 2; layer++)
    {
        vector<int> tmp;
        for (int i = layer; i <= m - layer + 1; i++) tmp.push_back(a[layer][i]);
        for (int i = layer + 1; i < n - layer + 1; i++) tmp.push_back(a[i][m - layer + 1]);
        for (int i = m - layer + 1; i >= layer; i--) tmp.push_back(a[n - layer + 1][i]);
        for (int i = n - layer; i > layer; i--) tmp.push_back(a[i][layer]);

        if (tmp.size() < 4) continue;
        for (int i = 0; i < tmp.size(); i++)
        {
            int a1 = tmp[i], a2 = tmp[(i + 1) % tmp.size()], a3 = tmp[(i + 2) % tmp.size()], a4 = tmp[(i + 3) % tmp.size()];

            res += (a1 == 1 && a2 == 5 && a3 == 4 && a4 == 3);
        }
    }

    cout << res << '\n';
}
