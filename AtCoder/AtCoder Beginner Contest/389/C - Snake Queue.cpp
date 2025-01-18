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
    int q; cin >> q;

    int pos = 0;
    ll sub = 0;
    vector<pair<ll, ll>> snakes;
    while (q--)
    {
        int type; cin >> type;

        if (type == 1)
        {
            int l; cin >> l;
            if (pos == (int)snakes.size())
            {
                snakes.push_back({0, l});
            } else
                snakes.push_back({snakes.back().first + snakes.back().second, l});
        } else
        if (type == 2)
        {
            sub += snakes[pos].second;
            pos++;
        } else
        {
            int k; cin >> k;
            cout << snakes[pos + k - 1].first - sub << '\n';
        }
    }
}
