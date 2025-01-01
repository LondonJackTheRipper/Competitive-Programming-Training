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
const int oo = 2e9;
const int maxn = 1e5 + 9;

struct Seg
{
    int r, a, b;

    Seg() = default;
    Seg(int r, int a, int b) : r(r), a(a), b(b) {}
    bool operator < (const Seg& other) const
    {
        if (r == other.r)
            return (a == other.a ? b < other.b : a < other.a);
        return r < other.r;
    }
};

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

map<pair<int, int>, int> mp;
vector<int> adj[maxn];
vector<Seg> seg(maxn);
int n, s, t, u, v;
int cur = 0;

int BFS(int source, int sink)
{
    vector<int> dist(cur + 1, oo);
    queue<int> q;
    q.push(source);
    dist[source] = 0;

    while (!q.empty())
    {
        int uu = q.front();
        q.pop();

        for (int vv : adj[uu])
        {
            if (dist[vv] != oo) continue;

            dist[vv] = dist[uu] + 1;
            q.push(vv);
        }
    }

    return dist[sink];
}

void solve()
{
    cin >> s >> t >> u >> v;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> seg[i].r >> seg[i].a >> seg[i].b;

    sort(seg.begin(), seg.begin() + n);
    for (Seg it : seg)
    {
        int r = it.r, a = it.a, b = it.b;

        for (int c = a; c <= b; c++)
        {
            if (mp[{r, c}] == 0)
                mp[{r, c}] = ++cur;
            for (int d = 0; d < 8; d++)
            {
                int rr = r + dx[d];
                int cc = c + dy[d];
                if (mp[{rr, cc}] != 0)
                {
                    adj[mp[{rr, cc}]].push_back(mp[{r, c}]);
                    adj[mp[{r, c}]].push_back(mp[{rr, cc}]);
                }
            }
        }
    }

    int res = BFS(mp[{s, t}], mp[{u, v}]);
    cout << (res == oo ? -1 : res) << '\n';
}
