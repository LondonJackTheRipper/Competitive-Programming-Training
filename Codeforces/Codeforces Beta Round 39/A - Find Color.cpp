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
    int x, y; cin >> x >> y;

    int dist = x * x + y * y, sq = sqrt(dist);
    if (dist == sq * sq)
    {
        cout << "black\n";
        return;
    }

    int num = sqrt(dist) + 1;
    int col = (x * y < 0 ? (num % 2 == 1 ? 1 : 0) : (num % 2 == 1 ? 0 : 1));

    cout << (col == 0 ? "black\n" : "white\n") << '\n';
}
