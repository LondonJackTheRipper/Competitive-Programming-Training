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
    int n, m;
    cin >> n >> m;
    int a[n + 1], b[m + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    vector<int> pre(m + 1, 0);
    int pos = 1;
    for (int i = 1; i <= m; i++)
    {
        while (pos <= n && a[pos] < b[i])
            pos++;

        pre[i] = (pos == n + 1 ? -1 : pos);
        if (pos != n + 1)
            pos++;
    }
    vector<int> suff(m + 2, 0);
    pos = n;
    for (int i = m; i > 0; i--)
    {
        while (pos > 0 && a[pos] < b[i])
            pos--;

        suff[i] = (pos == 0 ? -1 : pos);
        if (pos != 0)
            pos--;
    }
    pre[0] = 0;
    suff[m + 1] = n + 1;

    if (pre[m] != -1 || suff[1] != -1)
    {
        cout << 0 << '\n';
        return;
    }
    int res = 1e9 + 1;
    for (int i = 1; i <= m; i++)
    {
        if (pre[i - 1] == -1 || suff[i + 1] == -1)
            continue;

        if (pre[i - 1] < suff[i + 1])
            res = min(res, b[i]);
    }

    cout << (res == (int)1e9 + 1 ? -1 : res) << '\n';
}
