#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);

    int kk = k;
    int turns = 0, times = (k % 2 == 0 ? 5 : 4);
    while (kk > 0 && k - kk <= times)
    {
        kk--;
        if (turns == 0 && a[0] <= b[m - 1])
            swap(a[0], b[m - 1]);
        else
        if (turns == 1 && b[0] <= a[n - 1])
            swap(b[0], a[n - 1]);
        sort(a, a + n);
        sort(b, b + m);
        turns ^= 1;
    }

    ll res = 0;
    for (int i = 0; i < n; i++)
        res += a[i];
    cout << res << '\n';
}
