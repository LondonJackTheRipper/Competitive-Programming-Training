#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve();
signed main()
{
    solve();

    return 0;
}

// main program
const int maxn = 2e5 + 9;

vector<int> adj[maxn];
int par[maxn];
int n;

void DFS(int u, int p = -1)
{
    for (int v : adj[u])
    {
        if (v == p) continue;
        par[v] = u;
        DFS(v, u);
    }
}

void solve()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int p; cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    DFS(1);

    vector<int> res;
    for (int p = n; p != 0; p = par[p])
        res.push_back(p);
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << ' ';
}
