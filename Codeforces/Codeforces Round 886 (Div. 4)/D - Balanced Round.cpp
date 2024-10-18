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
    int n, k; cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    int fi = 1, la = 1;
    vector<pair<int, int>> proc;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] - a[i - 1] > k)
        {
            proc.push_back({fi, la});
            fi = la = i;
        } else
            la++;
    }
    proc.push_back({fi, la});

    int res = 1e9;
    for (pair<int, int> v : proc)
        res = min(res, n - (v.second - v.first + 1));

    cout << res << '\n';
}
