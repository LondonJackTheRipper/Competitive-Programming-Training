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
vector<pair<int, int>> adj[10009];
int n;

int encode(int i, int j)
{
    return n * (i - 1) + j;
}

void solve()
{
    cin >> n;
    char c[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        adj[0].push_back({encode(i, i), 0});
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] != '-')
                adj[0].push_back({encode(i, j), 1});
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int u = 1; u <= n; u++)
                for (int v = 1; v <= n; v++)
                    if (c[i][u] != '-' && c[i][u] == c[v][j])
                        adj[encode(u, v)].push_back({encode(i, j), 2});

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n * n + 1, 1e9);
    pq.push({dist[0] = 0, 0});
    while (!pq.empty())
    {
        int u = pq.top().second, w = pq.top().first;
        pq.pop();

        if (dist[u] != w)
            continue;

        for (pair<int, int> nxt : adj[u])
        {
            int v = nxt.first, ww = nxt.second;

            if (dist[v] > dist[u] + ww)
                pq.push({dist[v] = dist[u] + ww, v});
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int val = dist[encode(i, j)];
            cout << (val == (int)1e9 ? -1 : val) << ' ';
            if (j == n)
                cout << '\n';
        }
}
