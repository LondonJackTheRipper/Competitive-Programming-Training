#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 2e5 + 9;

vector<int> adj[maxn];
ll dp[maxn][2];
int arr[maxn];
int n, c;
ll res;

void DFS_DP(int u, int p = -1)
{
    dp[u][1] = arr[u];
    for (int v : adj[u])
    {
        if (v == p) continue;

        DFS_DP(v, u);

        dp[u][1] += max(dp[v][0], dp[v][1] - 2 * c);
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
    res = max(res, max(dp[u][0], dp[u][1]));
}

void input()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        adj[i].clear();
        dp[i][0] = dp[i][1] = 0ll;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    res = 0;
    DFS_DP(1);

    cout << res << '\n';
}

signed main()
{
	faster();

    int t; cin >> t;
    while (t--) input();

	return 0;
}
