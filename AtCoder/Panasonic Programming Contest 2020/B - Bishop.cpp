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
    int h, w; cin >> h >> w;

    if (h == 1 || w == 1)
    {
        cout << 1 << '\n';
        return;
    }

    int up = (w + 1) / 2, down = w / 2;
    cout << 1ll * up * ((h + 1) / 2) + 1ll * down * (h / 2) << '\n';
}

