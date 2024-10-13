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
void compute();
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
const int maxn = 10;

int n, s, t;
long double res = 1e9;
int a[maxn], b[maxn], c[maxn], d[maxn];

vector<int> vis;
vector<pair<int, int>> cur;
void backtrack(int pos)
{
    if (pos == n + 1)
    {
        compute();
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1) continue;

        vis[i] = 1;
        cur.push_back({a[i], b[i]});
        cur.push_back({c[i], d[i]});
        backtrack(pos + 1);
        cur.pop_back();
        cur.pop_back();

        cur.push_back({c[i], d[i]});
        cur.push_back({a[i], b[i]});
        backtrack(pos + 1);
        cur.pop_back();
        cur.pop_back();
        vis[i] = 0;
    }
}

long double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void compute()
{
    long double ans = 0;
    for (int i = 2; i < cur.size(); i += 2)
    {
        int x1 = cur[i - 2].first, y1 = cur[i - 2].second;
        int x2 = cur[i - 1].first, y2 = cur[i - 1].second;
        int x3 = cur[i].first, y3 = cur[i].second;
        ans += (dist(x1, y1, x2, y2) / s) + (dist(x2, y2, x3, y3) / t);
    }
    res = min(res, ans);
}

void solve()
{
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    cur.push_back({0, 0});
    vis.resize(n + 1, 0);

    backtrack(1);

    cout << fixed << setprecision(6) << res << '\n';
}
