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
const int maxnn = 100009;
const int maxn = 109;

int n, m, cur, total;
vector<int> adj[maxnn];
int s[maxn], d[maxn], c[maxn], ans[maxn];
int l[maxnn], r[maxn], par[maxn], id[maxnn];

int searcher()
{
    memset(par, 0, sizeof(par));
    queue<int> q;
    for (int i = 1; i <= cur; i++)
        if (l[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
            if (par[v] == 0)
            {
                par[v] = u;
                if (r[v] == 0) return v;
                q.push(r[v]);
            }
    }

    return -1;
}

void update(int v)
{
    while (v)
    {
        int u = par[v];
        int tmp = l[u];

        r[v] = u;
        l[u] = v;

        v = tmp;
    }
}

void solve()
{
    cin >> n >> m;
    cur = total = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> s[i] >> d[i] >> c[i];
        ans[d[i]] = m + 1;
        total += c[i];
    }
    for (int i = 1; i <= m; i++)
        for (int k = 0; k < c[i]; k++)
        {
            cur++;
            for (int j = s[i]; j < d[i]; j++)
            {
                if (ans[j] == m + 1) continue;
                adj[cur].push_back(j);

                id[cur] = i;
            }
        }

    int v;
    while ((v = searcher()) != -1) update(v);

    int maximum_matching = 0;
    for (int i = 1; i <= n; i++)
        maximum_matching += (r[i] != 0);

    if (maximum_matching != total)
    {
        cout << -1 << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
        if (r[i] != 0)
            ans[i] = id[r[i]];

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
