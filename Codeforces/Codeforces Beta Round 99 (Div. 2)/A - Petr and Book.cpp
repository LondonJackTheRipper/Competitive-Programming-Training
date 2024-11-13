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
    int total = 0;
    vector<int> a(7);
    for (int &x : a) cin >> x, total += x;
    for (int i = 1; i < 7; i++) a[i] += a[i - 1];
    n %= total;

    if (n == 0)
        n = total;

    cout << lower_bound(a.begin(), a.end(), n) - a.begin() + 1 << '\n';
}
