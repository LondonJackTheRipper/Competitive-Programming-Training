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
const int maxn = 21;

int n, m;
vector<int> ten(2 * maxn, 1);
vector<int> l[maxn], r[maxn];
int a[maxn][maxn];

void gen1(int u, int v, int sum)
{
    if (v == n + 1 - u)
    {
        l[u].push_back(sum);
        return;
    }

    if (u + 1 <= n)
        gen1(u + 1, v, (sum + a[u + 1][v]) % m);
    if (v + 1 <= n)
        gen1(u, v + 1, (sum + a[u][v + 1]) % m);
}

void gen2(int u, int v, int sum)
{
    if (v == n + 1 - u)
    {
        r[u].push_back(sum);
        return;
    }

    if (u - 1 >= 1)
        gen2(u - 1, v, (sum + a[u][v]) % m);
    if (v - 1 >= 1)
        gen2(u, v - 1, (sum + a[u][v]) % m);
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++)
        ten[i] = (ten[i - 1] * 10ll) % m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            a[i][j] = (1ll * a[i][j] * ten[2 * n - i - j]) % m;
        }

    gen1(1, 1, a[1][1]);
    gen2(n, n, 0);
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        sort(r[i].begin(), r[i].end());

        for (int x : l[i])
        {
            res = max(res, (x + r[i].back()) % m);

            int pos = lower_bound(r[i].begin(), r[i].end(), m - x) - r[i].begin();
            if (pos != 0)
                res = max(res, x + r[i][pos - 1]);
        }
    }

    cout << res << '\n';
}
