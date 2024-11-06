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

int n, m;
int mx[maxn];

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int l, r; cin >> l >> r;
        mx[r] = max(mx[r], l);
    }

    ll res = 0;
    int prefix_mx = 0;
    for (int i = 1; i <= m; i++)
    {
        prefix_mx = max(prefix_mx, mx[i]);

        res += i - prefix_mx;
    }

    cout << res << '\n';
}
