#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
const int maxn = 2e5 + 1;

struct State
{
    int sum;
    int mn, mx;
    int mn_pre, mx_pre, mn_suff, mx_suff;

    State(int x = 0)
    {
        sum = x;
        mn = mn_pre = mn_suff = min(0, x);
        mx = mx_pre = mx_suff = max(0, x);
    }
};

int par[18][maxn], h[maxn];
State ans[18][maxn];
int n, cur;

State Merge(State a, State b)
{
    State res;
    res.sum = a.sum + b.sum;
    res.mn = min({a.mn, b.mn, a.mn_suff + b.mn_pre});
    res.mx = max({a.mx, b.mx, a.mx_suff + b.mx_pre});
    res.mn_pre = min(a.mn_pre, a.sum + b.mn_pre);
    res.mx_pre = max(a.mx_pre, a.sum + b.mx_pre);
    res.mn_suff = min(b.mn_suff, b.sum + a.mn_suff);
    res.mx_suff = max(b.mx_suff, b.sum + a.mx_suff);

    return res;
}

void solve()
{
    cin >> n;
    cur = 1;
    ans[0][1] = State(1);

    while (n--)
    {
        char type; cin >> type;

        if (type == '+')
        {
            int v, x; cin >> v >> x;

            cur++;
            par[0][cur] = v;
            h[cur] = h[v] + 1;
            for (int i = 1; i < 18; i++)
                par[i][cur] = par[i - 1][par[i - 1][cur]];

            ans[0][cur] = State(x);
            for (int i = 1; i < 18; i++)
                ans[i][cur] = Merge(ans[i - 1][cur], ans[i - 1][par[i - 1][cur]]);
        } else
        {
            int u, v, k; cin >> u >> v >> k;

            if (h[u] < h[v]) swap(u, v);
            int dist = h[u] - h[v];
            State l, r;
            for (int i = 0; i < 18; i++)
                if (dist >> i & 1)
                {
                    l = Merge(l, ans[i][u]);
                    u = par[i][u];
                }

            if (u == v)
                l = Merge(l, ans[0][u]);
            else
            {
                for (int i = 17; i >= 0; i--)
                    if (par[i][u] != par[i][v])
                    {
                        l = Merge(l, ans[i][u]);
                        r = Merge(r, ans[i][v]);
                        u = par[i][u];
                        v = par[i][v];
                    }
                l = Merge(l, ans[1][u]);
                r = Merge(r, ans[0][v]);
            }

            int mn = min({l.mn, r.mn, l.mn_suff + r.mn_suff});
            int mx = max({l.mx, r.mx, l.mx_suff + r.mx_suff});

            cout << (mn <= k && k <= mx ? "YES\n" : "NO\n");
        }
    }
}
