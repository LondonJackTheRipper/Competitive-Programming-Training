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
    int n, l, r; cin >> n >> l >> r;
    ll a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<ll> le, m, ri;
    for (int i = 1; i < l; i++)
        le.push_back(a[i]);
    for (int i = l; i <= r; i++)
        m.push_back(a[i]);
    for (int i = r + 1; i <= n; i++)
        ri.push_back(a[i]);
    sort(le.begin(), le.end());
    sort(m.begin(), m.end(), greater<ll>());
    sort(ri.begin(), ri.end());
    vector<ll> pre1(le.begin(), le.end()), pre2(m.begin(), m.end()), pre3(ri.begin(), ri.end());
    for (int i = 1; i < (int)pre1.size(); i++)
        pre1[i] += pre1[i - 1];
    for (int i = 1; i < (int)pre2.size(); i++)
        pre2[i] += pre2[i - 1];
    for (int i = 1; i < (int)pre3.size(); i++)
        pre3[i] += pre3[i - 1];

    ll res = pre2[(int)pre2.size() - 1];
    for (int i = 0; i < l - 1; i++)
        if (i < (int)pre2.size())
            res = min(res, pre2[r - l] - pre2[i] + pre1[i]);
    for (int i = 0; i < n - r; i++)
        if (i < (int)pre2.size())
            res = min(res, pre2[r - l] - pre2[i] + pre3[i]);

    cout << res << '\n';
}
