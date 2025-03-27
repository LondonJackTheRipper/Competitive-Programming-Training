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
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
string str = "NWSE";

void solve()
{
    int n, r, c; cin >> n >> r >> c;
    map<pair<int, int>, int> mp;
    mp[{0, 0}] = 1;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        char ch; cin >> ch;

        int pos = str.find(ch);
        x += dx[pos];
        y += dy[pos];
        if (mp[{-x, -y}] == 0)
            mp[{-x, -y}] = 1;

        cout << mp[{r - x, c - y}];
    }
    cout << '\n';
}
