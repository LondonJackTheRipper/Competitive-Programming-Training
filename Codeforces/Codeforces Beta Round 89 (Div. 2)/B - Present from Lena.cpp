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
    int n; cin >> n;

    int fun;
    int mid = n + 1;
    for (int i = 1; i <= 2 * n + 1; i++)
        for (int j = 1; j <= 2 * n + 1; j++)
        {
            if (abs(mid - j) > n - abs(mid - i))
            {
                if (j <= mid) cout << "  ";
            }
            else
            {
                cout << n - abs(i - mid) - abs(mid - j);
                if (n - abs(i - mid) - abs(mid - j) == 0 && j >= mid) fun = 1; else cout << ' ';
            }

            if (j == 2 * n + 1) cout << '\n';
        }
}
