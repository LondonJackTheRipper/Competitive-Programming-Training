#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
    int n, t;
    cin >> n >> t;
    int a[n + 1];
    vector<int> cnt(301, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<int> dp_left(301, 0);
    for (int i = 1; i <= n; i++)
    {
        int mx = 0;
        for (int j = 0; j <= a[i]; j++)
            mx = max(mx, dp_left[j]);
        dp_left[a[i]] = max(dp_left[a[i]], mx + 1);
    }
    vector<int> dp_right(301, 0);
    for (int i = n; i > 0; i--)
    {
        int mx = 0;
        for (int j = a[i]; j < 301; j++)
            mx = max(mx, dp_right[j]);
        dp_right[a[i]] = max(dp_right[a[i]], mx + 1);
    }

    if (t <= 2 * n)
    {
        t--;
        while (t > 0)
        {
            for (int i = 1; i <= n; i++)
            {
                int mx = 0;
                for (int j = 0; j <= a[i]; j++)
                    mx = max(mx, dp_left[j]);
                dp_left[a[i]] = max(dp_left[a[i]], mx + 1);
            }
            t--;
        }
        int res = 0;
        for (int i = 0; i < 301; i++)
            res = max(res, dp_left[i]);
        cout << res << '\n';
        return;
    }

    for (int times = 1; times < n; times++)
    {
        for (int i = 1; i <= n; i++)
        {
            int mx = 0;
            for (int j = 0; j <= a[i]; j++)
                mx = max(mx, dp_left[j]);
            dp_left[a[i]] = max(dp_left[a[i]], mx + 1);
        }
        for (int i = n; i > 0; i--)
        {
            int mx = 0;
            for (int j = a[i]; j < 301; j++)
                mx = max(mx, dp_right[j]);
            dp_right[a[i]] = max(dp_right[a[i]], mx + 1);
        }
    }

    int res = 0;
    for (int i = 1; i < 301; i++)
    {
        if (cnt[i] == 0)
            continue;

        res = max(res, dp_left[i] + dp_right[i] + cnt[i] * (t - 2 * n));
    }

    cout << res << '\n';
}
