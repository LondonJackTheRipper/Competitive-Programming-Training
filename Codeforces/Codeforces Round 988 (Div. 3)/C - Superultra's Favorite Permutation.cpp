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
bool prime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return (n > 1);
}

void solve()
{
    int n; cin >> n;
    int x = -1, y = -1;
    int odd = (n % 2 == 1 ? n : n - 1);
    int even = (n % 2 == 0 ? n : n - 1);
    for (int i = 3; i <= odd + even; i += 2)
        if (!prime(i))
        {
            x = (i <= even + 1 ? 1 : i - even);
            y = (i > even + 1 ? even : i - 1);
            break;
        }

    if (x == -1)
    {
        cout << -1 << '\n';
        return;
    }

    for (int i = 1; i <= n; i += 2) if (i != x) cout << i << ' ';
    cout << x << ' ' << y << ' ';
    for (int i = 2; i <= n; i += 2) if (i != y) cout << i << ' '; cout << '\n';
}
