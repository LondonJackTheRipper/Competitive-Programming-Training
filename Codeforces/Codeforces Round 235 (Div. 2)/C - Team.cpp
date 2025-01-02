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

    solve();

    return 0;
}

// main program

void solve()
{
    int n, m; cin >> n >> m;

    if (n < (m - 1) / 2 || n > m + 1)
    {
        cout << -1 << '\n';
        return;
    }

    vector<int> mark(m, 0);
    for (int i = 2; i < m && n != 0; i += 2)
    {
        mark[i] = 1;
        n--;
    }
    for (int i = 0; i < m && n != 0; i++)
    {
        if (mark[i] == 1)
            continue;
        mark[i] = 1;
        n--;
    }

    for (int i = 0; i < m; i++)
    {
        if (mark[i] == 1) cout << 0;
        cout << 1;
    }
    if (n != 0) cout << 0;
    cout << '\n';
}
