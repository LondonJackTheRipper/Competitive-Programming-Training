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
    int n, k; cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int t[n + 1];
    for (int i = 1; i <= n; i++) cin >> t[i];

    vector<int> pre(n + 2, 0), non_pre(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1];
        non_pre[i] = non_pre[i - 1] + a[i];

        if (t[i] == 1)
            pre[i] += a[i];
    }

    int res = 0;
    for (int i = 1; i <= n - k + 1; i++)
    {
        int a = i, b = i + k - 1;

        res = max(res, non_pre[b] - non_pre[a - 1] + pre[a - 1] + pre[n] - pre[b]);
    }

    cout << res << '\n';
}
