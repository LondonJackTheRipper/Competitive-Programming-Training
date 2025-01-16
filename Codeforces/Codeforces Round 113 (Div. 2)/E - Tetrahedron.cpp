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
const int mod = 1e9 + 7;

void solve()
{
    int n; cin >> n;

    int D = 1, ABC = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp_D = (3ll * ABC) % mod;
        int tmp_ABC = (2ll * ABC + D) % mod;
        D = tmp_D;
        ABC = tmp_ABC;
    }

    cout << D << '\n';
}
