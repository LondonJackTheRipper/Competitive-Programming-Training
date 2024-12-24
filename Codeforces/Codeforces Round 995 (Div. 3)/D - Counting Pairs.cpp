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
struct FenwickTree
{
    int n;
    vector<int> bits;

    FenwickTree(int n) : n(n) { bits.resize(n + 1, 0); }

    void update(int pos, int val)
    {
        for (; pos <= n; pos += (pos & (-pos)))
            bits[pos] += val;
    }

    int query(int pos)
    {
        int res = 0;
        for (; pos > 0; pos -= (pos & (-pos)))
            res += bits[pos];
        return res;
    }
    int query(int l, int r) { return query(r) - query(l - 1); }
};

void solve()
{
    int n;
    ll x, y; cin >> n >> x >> y;
    int a[n + 1];
    ll sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];

    vector<ll> comp(a + 1, a + n + 1);
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    int cur = 0;
    map<int, int> cmp;
    for (ll x : comp)
        cmp[x] = ++cur;
    FenwickTree bit(cur);

    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        ll lef = -y + sum - a[i];
        ll rig = -x + sum - a[i];

        ll LEFT = lower_bound(comp.begin(), comp.end(), lef) - comp.begin();
        ll RIGH = upper_bound(comp.begin(), comp.end(), rig) - comp.begin();
        LEFT++;

        if (LEFT <= RIGH)
            res += bit.query(LEFT, RIGH);

        bit.update(cmp[a[i]], 1);
    }

    cout << res << '\n';
}
