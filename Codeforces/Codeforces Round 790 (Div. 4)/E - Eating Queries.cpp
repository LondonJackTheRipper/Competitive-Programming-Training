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
    int n, q; cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, greater<int>());
    vector<int> pre(a, a + n);
    for (int i = 1; i < n; i++)
        pre[i] += pre[i - 1];

    while (q--)
    {
        int x; cin >> x;

        int pos = lower_bound(pre.begin(), pre.end(), x) - pre.begin();

        cout << (pos == n ? -1 : pos + 1) << '\n';
    }
}
