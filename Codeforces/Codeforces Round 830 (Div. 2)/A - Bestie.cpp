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
int GCD(int a, int b) { return (b == 0 ? a : GCD(b, a % b)); }

void solve()
{
    int n; cin >> n;
    int a[n + 1];
    int total_gcd;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total_gcd = (i == 0 ? a[i] : GCD(a[i], total_gcd));
    }

    if (total_gcd == 1)
    {
        cout << 0 << '\n';
        return;
    }
    if (GCD(total_gcd, n) == 1)
    {
        cout << 1 << '\n';
        return;
    }
    if (GCD(total_gcd, n - 1) == 1)
    {
        cout << 2 << '\n';
        return;
    }
    cout << 3 << '\n';
}
