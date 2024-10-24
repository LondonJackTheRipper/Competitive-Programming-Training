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

ll sum(int l, int r) { return 1ll * (r + l) * (r - l + 2) / 4; }

void solve()
{
    int n, k; cin >> n >> k;

    if (k > ((n + 1) / 2) || ((k % 2) != (n % 2)))
    {
        cout << "NO\n";
        return;
    }

    int N = (n % 2 == 0 ? n - 1 : n);
    ll l = sum(1, 2 * (k - 1) + 1), r = sum(N - 2 * (k - 1), N);
    cout << (l <= n && n <= r ? "YES\n" : "NO\n");
}
