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
    int n, k; cin >> n >> k;
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (x % k != 0)
            ms.insert(k - (x % k));
    }

    n = ms.size();
    int cur_x = 0;
    ll res = 0;
    while (n--)
    {
        auto it = ms.lower_bound(cur_x);

        if (it != ms.end())
        {
            int val = (*it);
            ms.erase(it);
            res += val - cur_x + 1;
            cur_x = (val + 1) % k;
        } else
        {
            n++;
            res += k - cur_x;
            cur_x = 0;
        }
    }

    cout << res << '\n';
}
