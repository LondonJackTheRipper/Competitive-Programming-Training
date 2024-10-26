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

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m;

bool isin(int x, int y) { return (0 < min(x, y) && max(x, y) <= n); }

void solve()
{
    cin >> n >> m;
    set<pair<int, int>> se;
    while (m--)
    {
        int a, b; cin >> a >> b;
        se.insert({a, b});
        for (int d = 0; d < 8; d++)
        {
            int aa = a + dx[d];
            int bb = b + dy[d];

            if (!isin(aa, bb)) continue;
            se.insert({aa, bb});
        }
    }

    cout << 1ll * n * n - se.size() << '\n';
}
