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
    int a[n], b[n];
    b[n - 1] = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) cin >> b[i];
    sort(a, a + n, greater<int>());
    sort(b, b + n - 1, greater<int>());

    int res = -1;
    bool used = false;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= b[idx])
        {
            idx++;
            continue;
        }
        if (used == true)
        {
            cout << -1 << '\n';
            return;
        }
        used = true;
        res = a[i];
    }

    cout << res << '\n';
}