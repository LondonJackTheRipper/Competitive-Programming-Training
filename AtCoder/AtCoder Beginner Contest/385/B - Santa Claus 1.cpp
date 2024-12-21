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
const int maxn = 109;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int h, w, x, y;
string dir = "LRUD", t;
char s[maxn][maxn];

bool isin(int x, int y) { return 1 <= min(x, y) && x <= h && y <= w; }

void solve()
{
    cin >> h >> w >> x >> y;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> s[i][j];
    cin >> t;

    set<pair<int, int>> houses;
    for (char c : t)
    {
        int pos = dir.find(c);

        int xx = x + dx[pos];
        int yy = y + dy[pos];
        if (!isin(xx, yy) || s[xx][yy] == '#') continue;

        x = xx;
        y = yy;
        if (s[x][y] == '@') houses.insert({x, y});
    }

    cout << x << ' ' << y << ' ' << houses.size() << '\n';
}
