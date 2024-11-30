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
    string s; cin >> s;
    vector<int> prefix(n + 2, 0), suffix(n + 2, 0), right, val, tmp_val;
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + (s[i] == '1');
    for (int i = n - 1; i >= 0; i--)
        suffix[i + 1] = suffix[i + 2] + (s[i] == '2');
    for (int i = 0; i < n; i++)
        if (s[i] == '/')
        {
            right.push_back(i + 1);
            val.push_back(suffix[i + 1]);
        }

    while (q--)
    {
        int l, r; cin >> l >> r;
        int L = lower_bound(right.begin(), right.end(), l) - right.begin();
        int R = upper_bound(right.begin(), right.end(), r) - right.begin();

        if (L >= R)
        {
            cout << 0 << '\n';
            continue;
        }

        int res = 0;
        int i = 0, j = r - l + 1;
        while (i <= j)
        {
            int mid = i + j >> 1;

            int tmp = mid + suffix[r + 1];
            int u = L, v = R - 1;
            int pos = R;
            while (u <= v)
            {
                int m = u + v >> 1;

                if (val[m] >= mid + suffix[r + 1])
                {
                    pos = m;
                    u = m + 1;
                } else
                    v = m - 1;
            }

            if (pos == R || prefix[right[pos]] - prefix[l - 1] < mid)
                j = mid - 1;
            else
            {
                res = 2 * mid + 1;
                i = mid + 1;
            }
        }

        cout << res << '\n';
    }
}
