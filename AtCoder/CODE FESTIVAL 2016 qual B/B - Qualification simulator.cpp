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
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    int passed = 0, overseas = 1;
    for (char c : s)
    {
        if (c == 'c')
        {
            cout << "No\n";
        } else
        if (c == 'a')
        {
            if (passed < a + b)
            {
                passed++;
                cout << "Yes\n";
            } else
                cout << "No\n";
        } else
        {
            if (passed < a + b && overseas <= b)
            {
                overseas++;
                passed++;
                cout << "Yes\n";
            } else
                cout << "No\n";
        }
    }
}
