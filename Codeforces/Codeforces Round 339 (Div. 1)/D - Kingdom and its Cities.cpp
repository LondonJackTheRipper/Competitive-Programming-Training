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
const int maxn = 1e5;

int n, q, ans, exist;
int in[maxn + 1], out[maxn + 1], par[18][maxn + 1], h[maxn + 1], mark[2 * maxn + 1], sz[maxn];
vector<int> adj[maxn + 1], fake[2 * maxn + 1];

int timeDFS = 0;
void DFS(int u, int p = -1)
{
    in[u] = ++timeDFS;
    for (int v : adj[u])
    {
        if (v == p)
            continue;

        h[v] = h[u] + 1;
        par[0][v] = u;
        for (int i = 1; i < 18; i++)
            par[i][v] = par[i - 1][par[i - 1][v]];
        DFS(v, u);
    }
    out[u] = timeDFS;
}

bool cmp(int u, int v) { return in[u] < in[v]; }
bool inside(int p, int u) { return (in[p] <= in[u]) && (out[u] <= out[p]); }

int LCA(int u, int v)
{
    if (inside(u, v)) return u;
    if (inside(v, u)) return v;
    for (int i = 17; i >= 0; i--)
        if (h[u] >= (1 << i) && !inside(par[i][u], v))
            u = par[i][u];
    return par[0][u];
}

void DFS_SOLVE(int u, int p = -1)
{
    int cnt = 0;
    for (int v : fake[u])
    {
        if (v == p)
            continue;

        if (mark[u] == 1 && mark[v] == 1)
            if (h[v] - h[u] == 1)
                exist = 0;

        DFS_SOLVE(v, u);
        cnt += (sz[v] != 0);
    }

    if (mark[u] == 1)
        ans += cnt;
    else
        ans += (cnt > 1);
    sz[u] = mark[u];
    if (mark[u] == 0 && cnt == 1)
        sz[u] = 1;
}

void process_query(int k)
{
    vector<int> ver(k);
    for (int &v : ver)
    {
        cin >> v;
        mark[v] = 1;
    }
    sort(ver.begin(), ver.end(), cmp);
    for (int i = 1; i < k; i++)
        ver.push_back(LCA(ver[i - 1], ver[i]));
    sort(ver.begin(), ver.end(), cmp);
    ver.erase(unique(ver.begin(), ver.end()), ver.end());

    stack<int> st;
    st.push(ver[0]);
    k = ver.size();
    for (int i = 1; i < k; i++)
    {
        int u = ver[i];
        while (!inside(st.top(), u))
            st.pop();

        fake[st.top()].push_back(u);
        st.push(u);
    }

    ans = 0;
    exist = 1;
    DFS_SOLVE(ver[0]);
    cout << (exist == 0 ? -1 : ans) << '\n';

    for (int i = 0; i < k; i++)
    {
        fake[ver[i]].clear();
        mark[ver[i]] = 0;
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1);

    cin >> q;
    while (q--)
    {
        int k; cin >> k;

        process_query(k);
    }
}
