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
const int maxn = 2e5 + 9;

int n, k;
int a[maxn];

bool can(int x)
{
    ll total = 0;
    for (int i = (n + 1) / 2; i <= n; i++)
        total += max(x - a[i], 0);
    return (total <= k);
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    int l = 0, r = 2e9;
    int res = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (can(mid))
        {
            res = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }

    cout << res << '\n';
}
