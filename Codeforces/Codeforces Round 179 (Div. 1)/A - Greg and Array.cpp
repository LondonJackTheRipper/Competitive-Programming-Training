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
struct Query
{
    int l, r, d;

    Query() = default;
    Query(int l, int r, int d) : l(l), r(r), d(d) {}
};

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<Query> qr(m);
    for (Query &q : qr)
        cin >> q.l >> q.r >> q.d;

    vector<int> diff(m + 2, 0);
    while (k--)
    {
        int l, r; cin >> l >> r;;

        diff[r + 1]--;
        diff[l]++;
    }
    for (int i = 1; i <= m; i++)
        diff[i] += diff[i - 1];

    vector<ll> res(n + 2, 0);
    for (int i = 1; i <= n; i++)
        res[i] = a[i] - a[i - 1];
    for (int i = 0; i < m; i++)
    {
        ll d = 1ll * qr[i].d * diff[i + 1];
        res[qr[i].r + 1] -= d;
        res[qr[i].l] += d;
    }

    for (int i = 1; i <= n; i++)
    {
        res[i] += res[i - 1];

        cout << res[i] << ' ';
    }
}
