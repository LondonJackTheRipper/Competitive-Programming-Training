#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

string name = "test";

void solve();
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

// main program

void solve()
{
    int n, k1, k2; cin >> n >> k1 >> k2;
    int w, b; cin >> w >> b;

    if (k1 > k2) swap(k1, k2);

    if (w > k1 + (k2 - k1) / 2 || b > n - k2 + (k2 - k1) / 2)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
