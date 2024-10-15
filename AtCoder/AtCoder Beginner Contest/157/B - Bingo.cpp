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
    int a[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    int mark[3][3];
    int n; cin >> n;
    while (n--)
    {
        int x; cin >> x;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (a[i][j] == x)
                    mark[i][j] = 1;
    }

    // check for bingo
    for (int i = 0; i < 3; i++)
    {
        int num1 = 0, num2 = 0;
        for (int j = 0; j < 3; j++)
        {
            num1 += mark[i][j];
            num2 += mark[j][i];
        }
        if (num1 == 3 || num2 == 3)
        {
            cout << "Yes\n";
            return;
        }
    }
    if (mark[1][1] == 1 && ((mark[0][0] == 1 && mark[2][2] == 1) || (mark[0][2] == 1 && mark[2][0])))
    {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}
