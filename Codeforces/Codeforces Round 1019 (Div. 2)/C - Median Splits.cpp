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
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = (a[i] > k ? -1 : 1);
    }

    int u = -1, v = -1;
    vector<int> pre(n + 1, 0), suff(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
        suff[n - i + 1] = suff[n - i + 2] + a[n - i + 1];

        if (u == -1 && pre[i] >= 0) u = i;
        if (v == -1 && suff[n - i + 1] >= 0) v = n - i + 1;
    }
    vector<int> mx_l(n + 2, -1e9), mx_r(n + 2, -1e9);
    for (int i = n - 1; i > 0; i--)
    {
        mx_r[i] = max(mx_r[i + 1], pre[i]);
        mx_l[n - i + 1] = max(mx_l[n - i], suff[n - i + 1]);
    }

    bool res = false;
    // First and Third block
    if (u != -1 && v != -1 && u < v)
        res = true;
    // First, Second and Second, Third block
    for (int i = 1; i <= n; i++)
    {
        if (pre[i] >= 0 && mx_r[i + 1] >= pre[i])
            res = true;
        if (suff[i] >= 0 && mx_l[i - 1] >= suff[i])
            res = true;
    }

    cout << (res == true ? "YES\n" : "NO\n");
}
