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
    int k; cin >> k;
    int a[k];
    map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    for (int i = 0; i < k; i++)
    {
        int x = a[i];
        if ((k - 2) % x == 0)
        {
            int y = (k - 2) / x;
            if (x == y)
            {
                if (mp[y] >= 2)
                {
                    cout << x << ' ' << y << '\n';
                    return;
                }
            }
            else
                if (mp[y] >= 1)
            {
                cout << x << ' ' << y << '\n';
                return;
            }
        }
    }
}
