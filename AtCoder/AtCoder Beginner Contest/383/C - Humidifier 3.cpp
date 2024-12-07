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
struct state
{
    int x, y, steps;

    state() = default;
    state(int x, int y, int steps) : x(x), y(y), steps(steps) {};

    bool operator > (const state& other) const
    {
        return steps > other.steps;
    }
};

int mark[1009][1009];
int h, w, d;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isin(int x, int y) { return 0 <= min(x, y) && x < h && y < w; }

void solve()
{
    cin >> h >> w >> d;
    char c[h][w];
    priority_queue<state, vector<state>, greater<state>> pq;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == 'H')
                pq.push({i, j, 0});
        }

    int res = 0;
    while (!pq.empty())
    {
        int x = pq.top().x, y = pq.top().y;
        int steps = pq.top().steps;
        pq.pop();
        if (mark[x][y] == 1 || steps > d) continue;
        mark[x][y] = 1;
        res++;

        if (steps > d) continue;

        for (int d = 0; d < 4; d++)
        {
            int xx = x + dx[d];
            int yy = y + dy[d];

            if (!isin(xx, yy) || c[xx][yy] == 'H' || c[xx][yy] == '#' || mark[xx][yy] == 1) continue;

            pq.push({xx, yy, steps + 1});
        }
    }

    cout << res << '\n';
}
