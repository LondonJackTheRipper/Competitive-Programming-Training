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
const ll oo = 1e18;
const int maxn = 209;

struct Tram
{
    int x, y, p;

    Tram() = default;
    Tram(int x, int y, int p) : x(x), y(y), p(p) {};
};

ll mah(Tram a, Tram b)
{
    return 1ll * abs(a.x - b.x) + 1ll * abs(a.y - b.y);
}

void solve()
{
    int n; cin >> n;
    vector<Tram> trams(n);
    for (Tram &it : trams) cin >> it.x >> it.y >> it.p;

    vector<vector<ll>> dist(maxn, vector<ll>(maxn, oo));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            ll div1 = mah(trams[i], trams[j]) / trams[i].p;
            ll div2 = mah(trams[i], trams[j]) / trams[j].p;
            if (mah(trams[i], trams[j]) % trams[i].p != 0) div1++;
            if (mah(trams[i], trams[j]) % trams[j].p != 0) div2++;
            dist[i][j] = div1;
            dist[j][i] = div2;
        }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));

    ll res = oo;
    for (int i = 0; i < n; i++)
    {
        ll mx = 0;
        for (int j = 0; j < n; j++)
            mx = max(mx, dist[i][j]);

        res = min(res, mx);
    }

    cout << res << '\n';
}
