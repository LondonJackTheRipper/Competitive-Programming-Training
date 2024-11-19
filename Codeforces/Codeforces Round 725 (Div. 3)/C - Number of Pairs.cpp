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
    int n, l, r; cin >> n >> l >> r;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    // compress
    vector<int> v(a, a + n);
    sort(v.begin(), v.end());
    map<int, int> comp;
    int cur = 0;
    for (int x : v)
        if (comp[x] == 0) comp[x] = ++cur;
    //

    ll res = 0;
    FenwickTree bit(n);
    for (int i = 0; i < n; i++)
    {
        int LEFT = l - a[i], RIGHT = r - a[i];

        int pos1 = lower_bound(v.begin(), v.end(), LEFT) - v.begin();
        int pos2 = upper_bound(v.begin(), v.end(), RIGHT) - v.begin(); pos2--;

        if (pos1 <= pos2)
            res += bit.query(comp[v[pos1]], comp[v[pos2]]);

        bit.update(comp[a[i]], 1);
    }

    cout << res << '\n';
}
