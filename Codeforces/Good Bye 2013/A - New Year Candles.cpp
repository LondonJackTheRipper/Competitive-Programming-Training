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
    int a, b; cin >> a >> b;

    ll res = 0;
    int rem = a, rem_other = 0;
    while (rem)
    {
        res += rem;
        rem_other += (rem % b);
        rem /= b;
        rem += (rem_other / b);
        rem_other %= b;
    }

    cout << res << '\n';
}
