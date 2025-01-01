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
const int maxn = 1009;

void solve()
{
    int n; cin >> n;
    vector<int> X[maxn];
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        X[x].push_back(y);
    }
    for (int i = 0; i <= 1000; i++)
        sort(X[i].begin(), X[i].end());

    string dir = "";
    int cur_col = 0, cur_row = 0;
    for (int i = 0; i <= 1000; i++)
    {
        if (X[i].empty()) continue;

        while (cur_row < i)
        {
            dir.push_back('R');
            cur_row++;
        }
        if (X[i][0] < cur_col)
        {
            cout << "NO\n";
            return;
        }
        for (int x : X[i])
            while (cur_col < x)
            {
                dir.push_back('U');
                cur_col++;
            }
    }

    cout << "YES\n" << dir << '\n';
}
