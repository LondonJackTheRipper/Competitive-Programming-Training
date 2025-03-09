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
const int maxn = 2e5;

int n, m;
int visited[maxn + 1], val[maxn], ans[maxn];
vector<pair<int, int>> adj[maxn + 1];

vector<int> bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    vector<int> res = {u};

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (pair<int, int> nxt : adj[u])
        {
            int v = nxt.first, w = nxt.second;

            if (visited[v] == 0)
            {
                res.push_back(v);
                q.push(v);
                visited[v] = 1;
                val[v] = w ^ val[u];
            } else
                if ((val[u] ^ val[v]) != w)
                {
                    cout << -1 << '\n';
                    exit(0);
                }
        }
    }

    return res;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, z; cin >> x >> y >> z;

        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 1)
            continue;

        val[i] = 0;
        vector<int> order = bfs(i);
        for (int bit = 0; bit < 30; bit++)
        {
            int cnt = 0;
            for (int u : order)
                cnt += (val[u] >> bit & 1);

            if (cnt < order.size() - cnt)
            {
                for (int u : order)
                    if (val[u] >> bit & 1)
                        ans[u] |= (1 << bit);
            } else
                for (int u : order)
                    if (!(val[u] >> bit & 1))
                        ans[u] |= (1 << bit);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
