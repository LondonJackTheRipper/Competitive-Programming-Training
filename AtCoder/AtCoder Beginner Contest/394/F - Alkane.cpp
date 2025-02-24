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
const int maxn = 2e5 + 9;

vector<int> adj[maxn];
vector<int> dp(maxn, 0);
int n, ans = 0;

void DP_DFS(int u, int p = -1)
{
    dp[u] = 1;
    vector<int> proc;

    for (int v : adj[u])
    {
        if (v == p)
            continue;

        DP_DFS(v, u);
        proc.push_back(dp[v]);
    }

    sort(proc.begin(), proc.end(), greater<int>());
    if (!proc.empty())
        ans = max(ans, proc.front() + 1);
    if ((int)proc.size() >= 4)
        ans = max(ans, proc[0] + proc[1] + proc[2] + proc[3] + 1);
    if ((int)proc.size() >= 3)
        dp[u] = max(dp[u], proc[0] + proc[1] + proc[2] + 1);
}

void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DP_DFS(1);

    cout << (ans > 4 ? ans : -1) << '\n';
}
