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
    int n, t; cin >> n >> t;

    if (n == 1)
    {
        cout << (t == 10 ? -1 : t) << '\n';
        return;
    }

    int rem = 1;
    for (int i = 1; i < n; i++)
        rem = (rem * (10 % t)) % t;

    int lack = t - (rem == 0 ? t : rem);
    cout << 1;
    for (int i = 2; i < n; i++)
        cout << 0;
    cout << lack << '\n';
}
