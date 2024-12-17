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
    int n; cin >> n;
    ll d[n + 1];
    vector<ll> pre(n + 1, 0), suff(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        pre[i] = pre[i - 1] + d[i];
    }
    for (int i = n; i > 0; i--)
        suff[i] = suff[i + 1] + d[i];

    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = i + 1, r = n;
        int ans = -1;
        while (l <= r)
        {
            int mid = l + r >> 1;

            if (suff[mid] == pre[i])
            {
                ans = mid;
                break;
            } else
            if (suff[mid] > pre[i])
                l = mid + 1;
            else
                r = mid - 1;
        }

        if (ans != -1)
            res = max(res, pre[i]);
    }

    cout << res << '\n';
}
