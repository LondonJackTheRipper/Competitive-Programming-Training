#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

string name = "test";

void solve();
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

// main program
const int maxn = 2e5 + 9;

int n;
bool flag = true;
vector<int> adj[maxn];
int a[maxn], b[maxn], col[maxn];

void bipartite(int u, int color = 1)
{
    if (col[u] != 0) return;
    col[u] = color;

    for (int v : adj[u])
    {
        if (col[v] != 0)
        {
            if (col[v] == col[u])
            {
                flag = false;
                return;
            }
        } else
            bipartite(v, 3 - color);
    }
}

void solve()
{
    cin >> n;
    flag = true;
    map<int, int> mp;
    vector<int> pos[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        adj[i].clear();
        col[i] = 0;
        mp[a[i]]++;
        mp[b[i]]++;
        pos[a[i]].push_back(i);
        pos[b[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int nxt_a = (pos[a[i]][0] == i ? pos[a[i]][1] : pos[a[i]][0]);
        int nxt_b = (pos[b[i]][0] == i ? pos[b[i]][1] : pos[b[i]][0]);
        adj[i].push_back(nxt_a);
        adj[i].push_back(nxt_b);
    }

    for (auto it : mp)
        if (it.second != 2)
        {
            cout << "NO\n";
            return;
        }

    for (int i = 1; i <= n; i++)
        if (col[i] == 0)
            bipartite(i);

    cout << (flag ? "YES\n" : "NO\n");
}
