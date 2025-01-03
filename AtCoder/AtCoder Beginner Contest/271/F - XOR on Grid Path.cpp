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
const int maxn = 30;

int n;
int a[maxn][maxn];

vector<ll> lef[maxn], rig[maxn];
void gen1(int x = 1, int y = 1, ll cur = a[1][1])
{
    if (y > n + 1 - x) return;
    if (y == n + 1 - x)
    {
        lef[x].push_back(cur);
        return;
    }

    gen1(x + 1, y, cur ^ a[x + 1][y]);
    gen1(x, y + 1, cur ^ a[x][y + 1]);
}
void gen2(int x = n, int y = n, ll cur = a[n][n])
{
    if (y < n + 1 - x) return;
    if (y == n + 1 - x)
    {
        rig[x].push_back(cur ^ a[x][y]);
        return;
    }

    gen2(x - 1, y, cur ^ a[x - 1][y]);
    gen2(x, y - 1, cur ^ a[x][y - 1]);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    gen1();
    gen2();
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        map<ll, int> mp;
        for (ll x : lef[i])
            mp[x]++;
        for (ll x : rig[i])
            res += mp[x];
    }

    cout << res << '\n';
}
