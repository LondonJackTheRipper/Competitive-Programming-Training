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

    priority_queue<ll> pq;
    ll add = 0;
    while (q--)
    {
        int type; cin >> type;

        if (type == 1)
            pq.push(-add);
        else
        if (type == 2)
        {
            int t; cin >> t;
            add += t;
        } else
        {
            ll h; cin >> h;
            int res = 0;
            while (!pq.empty() && pq.top() + add >= h)
            {
                res++;
                pq.pop();
            }
            cout << res << '\n';
        }
    }
}
