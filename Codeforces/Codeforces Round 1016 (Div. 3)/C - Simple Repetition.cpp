#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
    int x, k; cin >> x >> k;

    if (x / 10 == 0 || k == 1)
    {
        ll num = 0;
        int cnt = 1, tmp = x;
        while (tmp) { cnt *= 10; tmp /= 10; }
        while (k--) num = num * cnt + x;
        for (int i = 2; 1ll * i * i <= num; i++)
            if (num % i == 0)
            {
                cout << "NO\n";
                return;
            }
        cout << (num > 1 ? "YES\n" : "NO\n");
    } else
        cout << "NO\n";
}
