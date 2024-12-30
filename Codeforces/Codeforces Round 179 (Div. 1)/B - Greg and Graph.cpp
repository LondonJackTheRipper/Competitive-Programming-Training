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
const int maxn = 509;
const int oo = 1e9 + 9;

int a[maxn][maxn], res[maxn][maxn];
int x[maxn], mark[maxn];
int n;

vector<int> dijkstra(int s, bool rev)
{
    vector<int> dist(n + 1, oo);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[s] = 0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (dist[u] != w) continue;

        for (int v = 1; v <= n; v++)
        {
            if (v == u || mark[v] == 0) continue;

            if (dist[v] > dist[u] + (rev == true ? a[v][u] : a[u][v]))
                pq.push({dist[v] = dist[u] + (rev == true ? a[v][u] : a[u][v]), v});
        }
    }

    return dist;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            res[i][j] = oo;
        }
    for (int i = 1; i <= n; i++)
        cin >> x[i];

    vector<ll> ans;
    for (int i = n; i > 0; i--)
    {
        mark[x[i]] = 1;

        vector<int> d1 = dijkstra(x[i], 0);
        vector<int> d2 = dijkstra(x[i], 1);
        for (int j = 1; j <= n; j++)
            if (j != x[i])
                res[x[i]][j] = d1[j];
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
            {
                if (u == v || mark[u] == 0 || mark[v] == 0) continue;
                res[u][v] = min(res[u][v], d2[u] + d1[v]);
            }

        ll cur_ans = 0;
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
            {
                if (u == v || mark[u] == 0 || mark[v] == 0) continue;
                cur_ans += res[u][v];
            }
        ans.push_back(cur_ans);
    }

    reverse(ans.begin(), ans.end());
    for (ll it : ans)
        cout << it << ' ';
    cout << '\n';
}
