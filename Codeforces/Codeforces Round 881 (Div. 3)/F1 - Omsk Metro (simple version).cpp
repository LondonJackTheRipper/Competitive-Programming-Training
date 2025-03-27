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
const int oo = 1e9;
const int maxn = 2e5 + 1;

struct State
{
    int mn, mx;
    int minSuff, maxSuff;

    State() : mn(oo), mx(0), minSuff(oo), maxSuff(0) {};
};

vector<int> g[maxn];
State ver[maxn];
int n;

void solve()
{
    cin >> n;
    ver[1].mn = ver[1].minSuff = 0;
    ver[1].mx = ver[1].maxSuff = 1;
    int cur = 1;
    while (n--)
    {
        char type; cin >> type;

        if (type == '+')
        {
            int v, x; cin >> v >> x;
            cur++;
            ver[cur].minSuff = min({0, x, ver[v].minSuff + x});
            ver[cur].maxSuff = max({0, x, ver[v].maxSuff + x});
            ver[cur].mn = min({ver[cur].minSuff, ver[v].mn});
            ver[cur].mx = max({ver[cur].maxSuff, ver[v].mx});
        } else
        {
            int u, v, k; cin >> u >> v >> k;

            cout << (ver[v].mn <= k && k <= ver[v].mx ? "YES\n" : "NO\n");
        }
    }
}
