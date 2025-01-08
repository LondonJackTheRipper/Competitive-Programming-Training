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
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        char c; cin >> c;

        cnt += (c == '0');
    }

    if (cnt % 2 == 0)
        cout << "BOB\n";
    else
        cout << (cnt == 1 ? "BOB\n" : "ALICE\n");
}
