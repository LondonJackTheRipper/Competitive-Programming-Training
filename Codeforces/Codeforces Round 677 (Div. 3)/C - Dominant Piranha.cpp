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
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    vector<int> pos;
    for (int i = 0; i < n; i++)
        if (a[i] == mx)
            pos.push_back({i});

    for (int it : pos)
    {
        int num = 0;
        if (it != 0 && a[it - 1] == mx) num++;
        if (it != n - 1 && a[it + 1] == mx) num++;

        if (num != (it != 0) + (it != n - 1))
        {
            cout << it + 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
