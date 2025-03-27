#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
const int maxn = 3e5;

int n, m;
int a[maxn + 1], b[maxn + 1];

bool can(ll k)
{
    ll left = 1ll * n * m;
    for (int i = 1; i <= n; i++)
    {
        ll tmp = k;
        if (a[i] >= b[i])
        {
            ll need = min(1ll * m, (tmp + a[i] - 1) / a[i]);
            tmp -= need * a[i];
            left -= need;
        }
        if (tmp > 0)
            left -= (tmp + b[i] - 1) / b[i];
        if (left < 0)
            break;
    }

    return (left >= 0);
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    ll l = 0, r = 1e18;
    ll res = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        if (can(mid))
        {
            res = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }

    cout << res << '\n';
}
