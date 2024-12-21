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
    int n, m;
    ll sx, sy;
    cin >> n >> m >> sx >> sy;
    vector<pair<ll, ll>> tmp(n), tmp1;
    vector<ll> rows(n), cols(n);
    vector<ll> rows1(n), cols1(n);
    for (pair<ll, ll> &it : tmp)
    {
        cin >> it.first >> it.second;
        tmp1.push_back({it.second, it.first});
    }
    sort(tmp.begin(), tmp.end());
    sort(tmp1.begin(), tmp1.end());
    for (int i = 0; i < n; i++)
    {
       rows[i] = tmp[i].first;
       cols[i] = tmp[i].second;
       rows1[i] = tmp1[i].first;
       cols1[i] = tmp1[i].second;
    }

    vector<ll> diff(n + 3, 0);
    vector<ll> diff1(n + 3, 0);
    while (m--)
    {
        char dir; cin >> dir;
        int c; cin >> c;
        ll cx = sx, cy = sy;

        if (dir == 'U') cy += c; else
        if (dir == 'D') cy -= c; else
        if (dir == 'L') cx -= c; else
        cx += c;

        ll tmp_sx = sx, tmp_sy = sy;
        sx = cx;
        sy = cy;

        if (dir == 'U' || dir == 'D')
        {
            ll a = tmp_sy, b = cy;
            if (dir == 'D') swap(a, b);
            int l = lower_bound(rows.begin(), rows.end(), cx) - rows.begin();
            if (l == rows.size() || rows[l] != cx) continue;
            int r = lower_bound(rows.begin(), rows.end(), cx + 1) - rows.begin();

            int lef = lower_bound(cols.begin() + l, cols.begin() + r, a) - cols.begin();
            if (lef == cols.size() || cols[lef] > b) continue;
            int rig = lower_bound(cols.begin() + l, cols.begin() + r, b + 1) - cols.begin();

            if (lef < rig)
            {
                diff[rig]--;
                diff[lef]++;
            }
        } else
        {
            ll a = tmp_sx, b = cx;
            if (dir == 'L') swap(a, b);
            int l = lower_bound(rows1.begin(), rows1.end(), cy) - rows1.begin();
            if (l == rows1.size() || rows1[l] != cy) continue;
            int r = lower_bound(rows1.begin(), rows1.end(), cy + 1) - rows1.begin();

            int lef = lower_bound(cols1.begin() + l, cols1.begin() + r, a) - cols1.begin();
            if (lef == cols1.size() || cols1[lef] > b) continue;
            int rig = lower_bound(cols1.begin() + l, cols1.begin() + r, b + 1) - cols1.begin();

            if (lef < rig)
            {
                diff1[rig]--;
                diff1[lef]++;
            }
        }
    }

    cout << sx << ' ' << sy << ' ';
    ll pre = 0, pre1 = 0;
    set<pair<ll, ll>> se;
    for (int i = 0; i < n; i++)
    {
        pre += diff[i];
        pre1 += diff1[i];

        if (pre > 0)
            se.insert({tmp[i].first, tmp[i].second});
        if (pre1 > 0)
            se.insert({tmp1[i].second, tmp1[i].first});
    }

    cout << se.size() << '\n';
}
