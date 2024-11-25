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
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll sum = 0;
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i += 2)
    {
        int x = a[i - 1], y = a[i];

        if (x > 0 && y > 0)
        {
            sum += x + y;
            continue;
        }
        if (x <= 0 && y > 0)
        {
            sum += max(x + y, -x - y);
            continue;
        }
        sum -= x + y;
    }
    sum += (n % 2 == 0 ? 0 : a[n]);

    cout << sum << '\n';
}
