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
    int n, a, b; cin >> n >> a >> b;

    if (a == 1)
    {
        cout << ((n - 1) % b == 0 ? "Yes\n" : "No\n");
        return;
    }
    ll cur = 1;
    while (cur <= n)
    {
        if ((cur % b) == (n % b))
        {
            cout << "Yes\n";
            return;
        }
        cur *= a;
    }

    cout << "No\n";
}
