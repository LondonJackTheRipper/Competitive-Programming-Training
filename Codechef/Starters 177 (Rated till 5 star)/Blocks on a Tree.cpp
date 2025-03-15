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

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// main program
const int maxn = 2000;

vector<int> adj[maxn + 1];
int sz[maxn + 1], labels[maxn + 1], res[maxn + 1];
stack<int> st;
int n, k, cnt;

void DFS(int u, int p = -1)
{
    cnt++;
    if (cnt <= k)
        labels[u] = 1;
    st.push(u);
    sz[u] = 1;
    
    for (int v : adj[u])
    {
        if (v == p)
            continue;
            
        DFS(v, u);
        sz[u] += sz[v];
    }
    
    if (sz[u] == k || sz[u] == n - k)
    {
        cout << 2 << '\n';
        vector<int> res(n + 1, (sz[u] == n - k && n - k != k));
        res[u] = (sz[u] == k);
        while (!st.empty() && st.top() != u)
        {
            res[st.top()] = (sz[u] == k);
            st.pop();
        }
        for (int i = 1; i <= n; i++)
            cout << res[i] << ' ';
        cout << '\n';
        throw 0;
    }
}

void solve()
{
    cin >> n >> k;
    cnt = 0;
    while (!st.empty()) st.pop();
    for (int i = 1; i <= n; i++)
    {
        labels[i] = 0;
        adj[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if (k % n == 0)
    {
        cout << 1 << '\n';
        for (int i = 1; i <= n; i++)
            cout << (k == n ? 1 : 0) << ' ';
        cout << '\n';
        return;
    }
    
    try { DFS(1); } catch(...) { return; }
    
    cout << 3 << '\n';
    for (int i = 1; i <= n; i++)
        cout << labels[i] << ' ';
    cout << '\n';
}
