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
    int n; cin >> n;

    int cnt2 = 0, cnt3 = 0;
    while (n % 2 == 0) cnt2++, n /= 2;
    while (n % 3 == 0) cnt3++, n /= 3;
    if (n != 1 || cnt3 < cnt2)
    {
        cout << -1 << '\n';
        return;
    }

    cout << 2 * cnt3 - cnt2 << '\n';
}
