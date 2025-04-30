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
const int maxn = 1001;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string dir = "DLRU";

char grid[maxn][maxn];
int dist[maxn][maxn];
int n, m, xs, ys, k;

bool isin(int x, int y) { return 1 <= min(x, y) && x <= n && y <= m && grid[x][y] != '*'; }

void BFS(int s, int t)
{
    memset(dist, -1, sizeof(dist));
    dist[s][t] = 0;
    queue<pair<int, int>> q;
    q.push({s, t});
    while (!q.empty())
    {
        int u = q.front().first, v = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int uu = u + dx[d];
            int vv = v + dy[d];
            if (!isin(uu, vv) || dist[uu][vv] != -1) continue;

            dist[uu][vv] = dist[u][v] + 1;
            q.push({uu, vv});
        }
    }
}

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'X')
            {
                xs = i;
                ys = j;
            }
        }
    if (k % 2 == 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    BFS(xs, ys);
    string res = "";
    while (k--)
    {
        bool proceed = false;
        for (int d = 0; d < 4; d++)
        {
            int x = xs + dx[d];
            int y = ys + dy[d];
            if (!isin(x, y) || dist[x][y] > k)
                continue;

            res.push_back(dir[d]);
            proceed = true;
            xs = x;
            ys = y;
            break;
        }
        if (proceed == false)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    cout << res << '\n';
}
