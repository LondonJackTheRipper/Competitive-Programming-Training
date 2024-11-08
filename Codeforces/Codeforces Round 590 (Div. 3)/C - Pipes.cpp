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
    char str[2][n];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> str[i][j];

    int cur_row = 0;
    for (int i = 0; i < n; i++)
    {
        int num = (str[cur_row][i] - '0');
        if (num > 2)
        {
            int num_other = (str[cur_row ^ 1][i] - '0');
            if (num_other > 2)
                cur_row ^= 1;
            else
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << (cur_row == 1 ? "YES\n" : "NO\n");
}
