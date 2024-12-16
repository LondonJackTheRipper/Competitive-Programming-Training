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
    vector<int> a(n), pre_mx(n, 0);
    vector<ll> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pre[i] = (i == 0 ? 0 : pre[i - 1]) + a[i];
        pre_mx[i] = max(i == 0 ? 0 : pre_mx[i - 1], a[i]);
    }

    while (q--)
    {
        int k; cin >> k;
        int pos = lower_bound(pre_mx.begin(), pre_mx.end(), k + 1) - pre_mx.begin();

        cout << (pos == 0 ? 0 : pre[pos - 1]) << ' ';
    }
    cout << '\n';
}
