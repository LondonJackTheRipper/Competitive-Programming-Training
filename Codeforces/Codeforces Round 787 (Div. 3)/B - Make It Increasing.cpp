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
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1]) continue;

        for (int j = i - 1; j >= 0; j--)
            while (a[j] >= a[j + 1])
            {
                if (a[j] == 0)
                {
                    cout << -1 << '\n';
                    return;
                }
                a[j] /= 2;
                res++;
            }
    }

    cout << res << '\n';
}
