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

// main program//

int GCD(int a, int b) { return (b == 0 ? a : GCD(b, a % b)); }
ll LCM(int a, int b) { return 1ll * a / GCD(a, b) * b; }

void solve()
{
    int n, m; cin >> n >> m;
    int a[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
            
    int v[n + 1];
    for (int i = 1; i <= n; i++)
    {
        ll cur = 1;
        for (int j = 1; j <= m; j++)
            cur = LCM(cur, a[i][j]);
        if (cur > 1e9)
        {
            cout << -1 << '\n';
            return;
        }
        v[i] = cur;
    }
    int u[m + 1];
    for (int i = 1; i <= m; i++)
    {
        ll cur = 1;
        for (int j = 1; j <= n; j++)
            cur = LCM(cur, a[j][i]);
        if (cur > 1e9)
        {
            cout << -1 << '\n';
            return;
        }
        u[i] = cur;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (GCD(v[i], u[j]) != a[i][j])
            {
                cout << -1 << '\n';
                return;
            }
    
    for (int i = 1; i <= n; i++) cout << v[i] << ' '; cout << '\n';
    for (int i = 1; i <= m; i++) cout << u[i] << ' '; cout << '\n';
}
