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

void solve()
{
    int n; cin >> n;
    bool zero = false;
    vector<int> neg, pos;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (x == 0)
            zero = true;

        if (x < 0)
            neg.push_back(x);
        else
            pos.push_back(x);
    }

    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end(), greater<int>());

    ll res = -1e18;
    if (zero) res = 0;
    for (int used = 0; used <= min((int)neg.size(), 5); used++)
    {
        if (5 - used > (int)pos.size()) continue;
        ll tmp1 = 1, tmp2 = 1;
        for (int j = 0; j < used; j++)
        {
            tmp1 *= neg[j];
            tmp2 *= neg[(int)neg.size() - j - 1];
        }
        for (int j = 0; j < 5 - used; j++)
        {
            tmp1 *= pos[j];
            tmp2 *= pos[j];
        }
        res = max({res, tmp1, tmp2});
    }

    cout << res << '\n';
}
;
