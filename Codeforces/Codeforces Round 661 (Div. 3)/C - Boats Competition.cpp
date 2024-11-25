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
    int w[n + 1];
    for (int i = 1; i <= n; i++) cin >> w[i];
    sort(w + 1, w + n + 1);

    int res = 0;
    for (int s = 1; s <= n * n; s++)
    {
        int l = 1, r = n;
        int tmp = 0;

        while (l < r)
        {
            int sum = w[l] + w[r];

            if (sum == s)
            {
                l++;
                r--;
                tmp++;
            } else
            if (sum > s)
                r--;
            else
                l++;
        }

        res = max(res, tmp);
    }

    cout << res << '\n';
}
