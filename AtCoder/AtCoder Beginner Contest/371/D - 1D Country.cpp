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
    vector<int> pos(n), num(n);
    for (int &x : pos) cin >> x;
    for (int &x : num) cin >> x;
    vector<ll> pre(num.begin(), num.end());
    for (int i = 1; i < n; i++)
        pre[i] += pre[i - 1];

    int q; cin >> q;
    while (q--)
    {
        int l, r; cin >> l >> r;

        int pos1 = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
        int pos2 = upper_bound(pos.begin(), pos.end(), r) - pos.begin();

        cout << (pos2 == 0 ? 0 : pre[pos2 - 1]) - (pos1 == 0 ? 0 : pre[pos1 - 1]) << '\n';
    }
}
