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

ll k;
int n;
int p[maxn], cycle[maxn], par[20][maxn];

int mul(int a, int b, int mod) { return 1ll * a * b % mod; }

int power(int a, ll b, int mod)
{
    int res = 1;
    while (b)
    {
        if (b % 2 == 1)
            res = mul(res, a, mod);
        a = mul(a, a, mod);
        b /= 2;
    }
    return res;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> p[i], par[0][i] = p[i];

    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1) continue;
        vis[i] = 1;

        int st = p[i], l = 1;
        while (st != i)
        {
            vis[st] = 1;
            st = p[st];
            l++;
        }

        cycle[i] = l;
        st = p[i];
        while (st != i)
        {
            cycle[st] = l;
            st = p[st];
        }
    }

    for (int i = 1; i < 20; i++)
        for (int u = 1; u <= n; u++)
            par[i][u] = par[i - 1][par[i - 1][u]];

    for (int i = 1; i <= n; i++)
    {
        int nxt = power(2, k, cycle[i]);

        int cur = i;
        for (int j = 0; j < 20; j++)
            if (nxt >> j & 1)
                cur = par[j][cur];

        cout << cur << ' ';
    }
    cout << '\n';
}
