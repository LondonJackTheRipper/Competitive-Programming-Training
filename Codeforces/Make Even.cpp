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
    string s = to_string(n);

    if (n % 2 == 0)
        cout << 0 << '\n';
    else
    {
        int fi = s[0] - '0';
        if (fi % 2 == 0)
            cout << 1 << '\n';
        else
        {
            bool check = false;
            for (char c : s)
                if (int(c - '0') % 2 == 0)
                    check = true;
            if (check)
                cout << 2 << '\n';
            else
                cout << -1 << '\n';
        }
    }
}
