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
const int oo = 1e9;
const int maxn = 1001;

struct State
{
    int w, x, y;

    State(int w, int x, int y) : w(w), x(x), y(y) {}
    bool operator > (const State& other) const
    {
        return w > other.w;
    }
};

char town[maxn][maxn];
int h, w, a, b, c, d;

int dx1[4] = {-1, 1, 0, 0};
int dy1[4] = {0, 0, -1, 1};
int dx2[4] = {-2, 2, 0, 0};
int dy2[4] = {0, 0, -2, 2};

bool isin(int x, int y) { return 1 <= min(x, y) && x <= h && y <= w; }

void solve()
{
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> town[i][j];
    cin >> a >> b >> c >> d;

    vector<vector<int>> dist(h + 1, vector<int>(w + 1, oo));
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push(State(dist[a][b] = 0, a, b));
    while (!pq.empty())
    {
        State tp = pq.top();
        pq.pop();

        int u = tp.x, v = tp.y, w = tp.w;
        if (w != dist[u][v])
            continue;

        for (int d = 0; d < 4; d++)
        {
            int uu = u + dx1[d], vv = v + dy1[d];
            if (!isin(uu, vv))
                continue;

            int new_w = w + (town[uu][vv] == '#' ? 1 : 0);
            bool temp = (town[uu][vv] == '#' ? 1 : 0);
            if (dist[uu][vv] > new_w)
                pq.push({dist[uu][vv] = new_w, uu, vv});

            uu = u + dx2[d];
            vv = v + dy2[d];
            if (!isin(uu, vv))
                continue;
            new_w = w + ((town[uu][vv] == '#' ? 1 : 0) | temp);
            if (dist[uu][vv] > new_w)
                pq.push({dist[uu][vv] = new_w, uu, vv});
        }
    }

    cout << dist[c][d] << '\n';
}
