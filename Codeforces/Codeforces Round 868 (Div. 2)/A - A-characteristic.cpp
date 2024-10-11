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
int C(int n) { return n * (n - 1) / 2; }

void solve()
{
    int n, k; cin >> n >> k;

    for (int i = 0; i <= n; i++)
    {
        int total = C(i) + C(n - i);

        if (total == k)
        {
            cout << "YES\n";
            for (int j = 0; j < i; j++) cout << 1 << ' ';
            for (int j = 0; j < n - i; j++) cout << -1 << ' ';
            cout << '\n';
            return;
        }
    }
    cout << "NO\n";
}
