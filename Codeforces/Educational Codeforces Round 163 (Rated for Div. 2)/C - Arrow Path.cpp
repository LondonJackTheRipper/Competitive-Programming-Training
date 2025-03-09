#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

const int maxn = 2e5;

vector<int> adj[2 * maxn];
int reach[2 * maxn];

void dfs(int u)
{
    reach[u] = 1;
    for (int v : adj[u])
        if (reach[v] == 0)
            dfs(v);
}

void solve()
{
    int n; cin >> n;
    vector<vector<char>> v(2, vector<char>(n));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    for (int i = 0; i < 2 * n; i++)
    {
        adj[i].clear();
        reach[i] = 0;
    }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            for (int d = 0; d < 4; d++)
            {
                int ii = i + dx[d], jj = j + dy[d];
                if (0 <= ii && ii < 2 && 0 <= jj && jj < n)
                {
                    jj += (v[ii][jj] == '<' ? -1 : 1);
                    adj[i * n + j].push_back(ii * n + jj);
                }
            }

    dfs(0);

    cout << (reach[2 * n - 1] == 1 ? "YES\n" : "NO\n");
}
