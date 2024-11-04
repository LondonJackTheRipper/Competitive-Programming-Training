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
    int r, c;
    char o;

    Query() = default;
    Query(int r, char o, int c) : r(r), o(o), c(c) {}
};

void solve()
{
    int n, k, q; cin >> n >> k >> q;
    ll a[n + 1][k + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            cin >> a[i][j];
    vector<ll> OR[k + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            a[i][j] |= (i == 1 ? 0 : a[i - 1][j]);
            OR[j].push_back(a[i][j]);
        }

    while (q--)
    {
        int m; cin >> m;
        map<int, pair<int, int>> mp;
        vector<Query> qr(m);
        for (Query &Q : qr)
        {
            cin >> Q.r >> Q.o >> Q.c;

            mp[Q.r] = {-1, -1};
        }
        for (Query Q : qr)
        {
            int r = Q.r, c = Q.c;
            char o = Q.o;

            if (o == '>')
                mp[r].first = max(mp[r].first, c);
            else
            {
                if (mp[r].second == -1)
                    mp[r].second = c;
                else
                    mp[r].second = min(mp[r].second, c);
            }
        }

        vector<pair<int, int>> TMP;
        int sz = 0;
        for (auto it : mp)
        {
            int row = it.first;
            ll l = it.second.first, r = (it.second.second == -1 ? 1e18 : it.second.second);
            sz++;

            int pos1 = upper_bound(OR[row].begin(), OR[row].end(), l) - OR[row].begin();
            int pos2 = lower_bound(OR[row].begin(), OR[row].end(), r) - OR[row].begin(); pos2--;

            TMP.push_back({pos1 + 1, pos2 + 1});
        }

        int idx = 1;
        bool flag = false;
        for (pair<int, int> t : TMP)
        {
            int fi = t.first, se = t.second;
            if (fi > se)
                flag = true;

            idx = max(idx, fi);
        }
        for (pair<int, int> t : TMP)
            if (idx > t.second)
                flag = true;

        cout << (flag == true ? -1 : idx) << '\n';
    }
}
