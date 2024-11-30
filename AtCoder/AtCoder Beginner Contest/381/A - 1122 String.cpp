#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

const string name = "test";

void solve();
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}

// main program

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    if (n % 2 == 0)
    {
        cout << "No" << '\n';
        return;
    }
    for (int i = 0; i < n / 2; i++)
        if (s[i] != '1')
        {
            cout << "No" << '\n';
            return;
        }
    if (s[n / 2] != '/')
    {
        cout << "No" << '\n';
        return;
    }
    for (int i = n / 2 + 1; i < n; i++)
        if (s[i] != '2')
        {
        cout << "No" << '\n';
        return;
        }
    cout << "Yes\n";
}
