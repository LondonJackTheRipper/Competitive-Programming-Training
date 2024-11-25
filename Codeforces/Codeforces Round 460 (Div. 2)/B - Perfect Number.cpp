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
    int k; cin >> k;
    for (int i = 1; i <= 20000000; i++)
    {
        int sum = 0, tmp = i;
        while (tmp)
        {
            sum += (tmp % 10);
            tmp /= 10;
        }
        if (sum == 10)
        {
            k--;
            if (k == 0)
            {
                cout << i << '\n';
                return;
            }
        }
    }
}
