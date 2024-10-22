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

void solve()
{
    int n; cin >> n;
    int l[n + 1], r[n + 1], pos[n + 1];
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        pos[x] = i;
        l[i + 1] = r[i + 1] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        int go_left = (i < pos[x] ? i + n - pos[x] : i - pos[x]);
        int go_right = (i < pos[x] ? pos[x] - i : n - i + pos[x]);
        l[go_left]++;
        r[go_right]++;
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max({res, l[i], r[i]});
    cout << res << '\n';
}
