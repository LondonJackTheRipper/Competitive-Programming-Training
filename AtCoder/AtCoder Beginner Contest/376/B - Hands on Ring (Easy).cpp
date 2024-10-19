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
    int n, q; cin >> n >> q;
    int l = 1, r = 2;

    int total = 0;

    while (q--)
    {
        char h; cin >> h;
        int t; cin >> t;

        int res1 = 0, res2 = 0;
        if (h == 'L')
        {
            int tmp1 = l, tmp2 = l;
            while (tmp1 != t || tmp2 != t)
            {
                if (tmp1 != t)
                {
                    tmp1++;
                    if (tmp1 == n + 1) tmp1 = 1;
                    if (tmp1 == r)
                        res1 = 1e9;
                    res1++;
                }
                if (tmp2 != t)
                {
                    tmp2--;
                    if (tmp2 == 0) tmp2 = n;
                    if (tmp2 == r)
                        res2 = 1e9;
                    res2++;
                }
            }
            l = t;
        } else
        {
            int tmp1 = r, tmp2 = r;
            while (tmp1 != t || tmp2 != t)
            {
                if (tmp1 != t)
                {
                    tmp1++;
                    if (tmp1 == n + 1) tmp1 = 1;
                    if (tmp1 == l)
                        res1 = 1e9;
                    res1++;
                }
                if (tmp2 != t)
                {
                    tmp2--;
                    if (tmp2 == 0) tmp2 = n;
                    if (tmp2 == l)
                        res2 = 1e9;
                    res2++;
                }
            }
            r = t;
        }

        total += min(res1, res2);
    }

    cout << total << '\n';
}
