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
const int maxn = 109;

vector<int> adj[maxn];
ll a[maxn];
int n;

void reset()
{
    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

void travel(int u, vector<int>& vis, vector<int>& ans)
{
    ans.push_back(u);
    vis[u] = 1;

    for (int v : adj[u])
    {
        if (vis[v] == 1) continue;

        travel(v, vis, ans);
    }
}

void solve()
{
    cin >> n;
    reset();
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] * 2 == a[j] || (a[i] % 3 == 0 && a[i] / 3 == a[j]))
                adj[i].push_back(j);

    for (int i = 1; i <= n; i++)
    {
        vector<int> vis(n + 1, 0), ans;
        travel(i, vis, ans);

        if (ans.size() == n)
        {
            for (int x : ans) cout << a[x] << ' ';
            cout << '\n';
            return;
        }
    }
}
