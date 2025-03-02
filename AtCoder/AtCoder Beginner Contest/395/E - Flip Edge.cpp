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
const ll oo = 1e18;
const int maxn = 2e5 + 1;

vector<int> adj[maxn], rev[maxn];
int n, m, x;

struct State
{
    ll w;
    int u, turns;

    State(ll w, int u, int turns) : w(w), u(u), turns(turns) {};
    bool operator > (const State& other) const
    {
        return w > other.w;
    }
};

void dijkstra(int s)
{
    vector<vector<ll>> dist(2, vector<ll>(n + 1, oo));
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({dist[0][s] = 0, s, 0});
    pq.push({dist[1][s] = x, s, 1});

    while (!pq.empty())
    {
        ll w = pq.top().w;
        int u = pq.top().u;
        int turns = pq.top().turns;
        pq.pop();

        if (dist[turns][u] != w)
            continue;

        vector<int> adjacent = (turns == 0 ? adj[u] : rev[u]);
        for (int v : adjacent)
            if (dist[turns][v] > dist[turns][u] + 1)
                pq.push({dist[turns][v] = dist[turns][u] + 1, v, turns});

        adjacent = (turns == 0 ? rev[u] : adj[u]);
        turns ^= 1;
        for (int v : adjacent)
            if (dist[turns][v] > w + x + 1)
                pq.push({dist[turns][v] = w + x + 1, v, turns});
    }

    cout << min(dist[0][n], dist[1][n]) << '\n';
}

void solve()
{
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    dijkstra(1);
}
