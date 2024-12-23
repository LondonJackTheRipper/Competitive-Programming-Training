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
    string s; cin >> s;

    if ((int)s.length() < 2)
    {
        cout << 0 << '\n';
        return;
    }

    int sum = 0;
    for (char c : s)
        sum += (c - '0');

    int res = 1;
    while (sum > 9)
    {
        int new_sum = 0;
        while (sum)
        {
            new_sum += (sum % 10);
            sum /= 10;
        }

        sum = new_sum;
        res++;
    }

    cout << res << '\n';
}
