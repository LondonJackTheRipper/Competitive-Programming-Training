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
bool isin(int x) { return (-1000 <= x && x <= 1000); }

void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2)
    {
        int x_1 = x1 + abs(y1 - y2), x_2 = x1 - abs(y1 - y2);
        if (isin(x_1))
            cout << x_1 << ' ' << y1 << ' ' << x_1 << ' ' << y2 << '\n';
        else
        if (isin(x_2))
            cout << x_2 << ' ' << y1 << ' ' << x_2 << ' ' << y2 << '\n';
        else
            cout << -1 << '\n';
        return;
    } else
    if (y1 == y2)
    {
        int y_1 = y1 + abs(x1 - x2), y_2 = y1 - abs(x1 - x2);
        if (isin(y_1))
            cout << x1 << ' ' << y_1 << ' ' << x2 << ' ' << y_1 << '\n';
        else
        if (isin(y_2))
            cout << x1 << ' ' << y_2 << ' ' << x2 << ' ' << y_2 << '\n';
        else
            cout << -1 << '\n';
        return;
    }
    if (abs(x1 - x2) != abs(y1 - y2))
    {
        cout << -1 << '\n';
        return;
    }
    cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1 << '\n';
}
