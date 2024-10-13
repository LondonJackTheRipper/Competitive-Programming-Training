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
    int x, n, m; cin >> x >> n >> m;

    while (n--)
    {
        int nxt = x / 2 + 10;
        if (nxt < x)
            x = nxt;
        else
            break;
    }
    while (m--)
    {
        if (x - 10 <= 0)
        {
            cout << "YES\n";
            return;
        }
        x -= 10;
    }
    cout << "NO\n";
}
