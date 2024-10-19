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
const int oo = 1e9;
const int maxn = 2e5 + 9;

vector<int> adj[maxn];
vector<int> rev;
int n, m;

vector<int> BFS(int s)
{
    queue<int> q;
    vector<int> dist(n + 1, oo);
    dist[s] = 0;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (dist[v] != oo) continue;

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    return dist;
}

void solve()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        if (b == 1)
            rev.push_back(a);
    }

    vector<int> dist = BFS(1);

    if (rev.empty())
        cout << -1 << '\n';
    else
    {
        int mn = 1e9;
        for (int v : rev)
            mn = min(mn, dist[v]);
        cout << (mn == 1e9 ? -1 : mn + 1) << '\n';
    }
}
