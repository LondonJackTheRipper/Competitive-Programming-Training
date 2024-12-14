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
const int maxn = 509;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int h, w, p, q;
ll x;

ll c[maxn][maxn];
int mark[maxn][maxn];

struct State
{
    ll val;
    int x, y;

    State() = default;
    State(ll val, int x, int y) : val(val), x(x), y(y) {};

    bool operator > (const State& other) const
    {
        return val > other.val;
    }
};

priority_queue<State, vector<State>, greater<State>> pq;

bool isin(int x, int y) { return 0 < min(x, y) && x <= h && y <= w; }

void solve()
{
    cin >> h >> w >> x >> p >> q;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> c[i][j];

    ll res = 0;
    mark[p][q] = 1;
    bool root = true;
    pq.push({c[p][q], p, q});
    while (!pq.empty())
    {
        ll val = pq.top().val;
        int u = pq.top().x;
        int v = pq.top().y;
        pq.pop();

        ll limit = res / x;
        if (res % x != 0) limit++;

        if (val >= limit && root == false)
            break;

        root = false;

        res += val;
        for (int d = 0; d < 4; d++)
        {
            int xx = u + dx[d];
            int yy = v + dy[d];
            if (!isin(xx, yy) || mark[xx][yy] == 1) continue;

            mark[xx][yy] = 1;
            pq.push({c[xx][yy], xx, yy});
        }
    }

    cout << res << '\n';
}
