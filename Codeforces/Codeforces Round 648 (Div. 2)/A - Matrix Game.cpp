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
    vector<int> row(n, 0), col(m, 0);
    int r = n, c = m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int x; cin >> x;
            if (x == 0) continue;
            if (row[i] == 0)
            {
                row[i] = 1;
                r--;
            }
            if (col[j] == 0)
            {
                col[j] = 1;
                c--;
            }
        }

    cout << (min(r, c) % 2 == 1 ? "Ashish\n" : "Vivek\n");
}
