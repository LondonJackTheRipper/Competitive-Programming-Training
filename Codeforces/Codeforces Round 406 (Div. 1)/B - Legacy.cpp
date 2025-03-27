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
const ll oo = 1e18;
const int maxn = 1e5 + 1;

int n, q, s;
int mx = 0;
vector<pair<int, int>> g[10 * maxn];

void build1(int head, int par, int l, int r)
{
    mx = max(mx, head + n);
    if (par != -1)
        g[par + n].push_back({head + n, 0});

    if (l != r)
    {
        int mid = l + r >> 1;
        build1(2 * head, head, l, mid);
        build1(2 * head + 1, head, mid + 1, r);
    } else
        g[head + n].push_back({l, 0});
}
void build2(int head, int par, int l, int r)
{
    if (par != -1)
        g[head + mx].push_back({par + mx, 0});

    if (l != r)
    {
        int mid = l + r >> 1;
        build2(2 * head, head, l, mid);
        build2(2 * head + 1, head, mid + 1, r);
    } else
        g[l].push_back({head + mx, 0});
}

void Segment(int head, int l, int r, int u, int v, vector<int>& proc)
{
    if (l > v || r < u) return;
    if (u <= l && r <= v)
    {
        proc.push_back(head);
        return;
    }

    int mid = l + r >> 1;
    Segment(2 * head, l, mid, u, v, proc);
    Segment(2 * head + 1, mid + 1, r, u, v, proc);
}

vector<ll> Dijkstra(int s)
{
    vector<ll> dist(10 * maxn, oo);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({dist[s] = 0, s});

    while (!pq.empty())
    {
        ll w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] != w)
            continue;

        for (pair<int, int> nxt : g[u])
        {
            int v = nxt.first, ww = nxt.second;
            if (dist[v] > dist[u] + ww)
                pq.push({dist[v] = dist[u] + ww, v});
        }
    }

    return dist;
}

void solve()
{
    cin >> n >> q >> s;
    build1(1, -1, 1, n);
    build2(1, -1, 1, n);
    while (q--)
    {
        int t; cin >> t;

        if (t == 1)
        {
            int v, u, w; cin >> v >> u >> w;
            g[v].push_back({u, w});
        } else
        {
            int v, l, r, w; cin >> v >> l >> r >> w;
            vector<int> proc;
            Segment(1, 1, n, l, r, proc);

            if (t == 2)
            {
                for (int x : proc)
                    g[v].push_back({x + n, w});
            } else
            {
                for (int x : proc)
                    g[x + mx].push_back({v, w});
            }
        }
    }

    vector<ll> dist = Dijkstra(s);
    for (int i = 1; i <= n; i++)
        cout << (dist[i] == oo ? -1 : dist[i]) << ' ';
    cout << '\n';
}
