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
    ll res = 0;
    int neg = 0, pos = 0;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;

        if (x < 0)
        {
            res += -1 - x;
            neg++;
        } else
        if (x > 0)
        {
            res += x - 1;
            pos++;
        }
    }
    int num0 = n - pos - neg;

    cout << (neg % 2 == 0 ? res + num0 : (num0 == 0 ? res + 2 : res + 1 + num0 - 1)) << '\n';
}
