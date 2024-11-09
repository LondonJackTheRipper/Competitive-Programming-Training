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
ll segment(ll l, ll r) { return r * (r + 1) / 2 - l * (l - 1) / 2; }

void solve()
{
    int n, m; cin >> n >> m;
    ll total = 0;
    vector<pair<int, ll>> st(m);
    for (pair<int, ll> &x : st) cin >> x.first;
    for (pair<int, ll> &x : st) cin >> x.second, total += x.second;
    sort(st.begin(), st.end());

    if (st.front().first != 1 || total != n)
    {
        cout << -1 << '\n';
        return;
    }

    ll res = 0;
    st.push_back({n, 0});
    for (int i = 0; i < m; i++)
    {
        ll cur = st[i].first, nxt = st[i + 1].first;
        ll need = nxt - cur - 1;
        if (need > st[i].second - 1)
        {
            cout << -1 << '\n';
            return;
        }

        res += segment(1, need) + (st[i].second - 1 - need) * (need + 1);
        st[i + 1].second += st[i].second - 1 - need;
    }

    cout << res << '\n';
}
