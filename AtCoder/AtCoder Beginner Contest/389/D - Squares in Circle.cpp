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
#define ld long double
ld dist(ld a, ld b, ld c, ld d)
{
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

void solve()
{
    int r; cin >> r;

    int col = r;
    ll sum = 0;
    for (int row = 0; row <= r; row++)
    {
        while (col > 0 && dist(0, 0, (long double)row + 0.5, (long double)col + 0.5) > (long double)r)
            col--;

        sum += r - col;
    }

    cout << 1ll * (2 * r + 1) * (2 * r + 1) - 4 * sum << '\n';
}
