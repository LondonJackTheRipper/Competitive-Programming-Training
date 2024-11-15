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
    int n, k; cin >> n >> k;

    int up, dn;
    for (int i = n - 1; i > 0; i--)
    {
        int rem = n - i;
        k -= rem;

        if (k <= 0)
        {
            k += rem;
            up = n - k + 1;
            dn = i;
            break;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << (i == up || i == dn ? 'b' : 'a');
    cout << '\n';
}
