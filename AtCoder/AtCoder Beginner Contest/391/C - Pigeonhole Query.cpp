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
    int n, q; cin >> n >> q;

    int cnt = 0;
    map<int, int> mp;
    vector<int> nest(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        mp[i] = 1;
        nest[i] = i;
    }
    while (q--)
    {
        int type; cin >> type;

        if (type == 1)
        {
            int p, h; cin >> p >> h;
            mp[nest[p]]--;
            mp[h]++;
            if (mp[nest[p]] == 1)
                cnt--;
            if (mp[h] == 2)
                cnt++;
            nest[p] = h;
        } else
            cout << cnt << '\n';
    }
}
