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
    int n, m; cin >> n >> m;
    vector<int> tasks(n, 0);
    while (m--)
    {
        int x; cin >> x;
        tasks[x - 1]++;
    }

    int l = 0, r = 2e5;
    int res = -1;
    while (l <= r)
    {
        int mid = l + r >> 1;

        ll rem = 0, need = 0;
        for (int i = 0; i < n; i++)
        {
            int comp = min(mid, tasks[i]);

            need += max(0, tasks[i] - mid);
            rem += max(0, mid - tasks[i]) / 2;
        }

        if (rem >= need)
        {
            res = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }

    cout << res << '\n';
}
