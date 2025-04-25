#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
const int maxn = 2e5 + 1;

int p[maxn];

void solve()
{
    int n, q;
    cin >> n >> q;
    int pos[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i;
    }

    for (int i = 1; i <= q; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;

        if (!(l <= pos[x] && pos[x] <= r))
        {
            cout << -1 << ' ';
            continue;
        }

        int pro_l = l, pro_r = r;
        vector<int> LL, GG;
        while (pro_l <= pro_r)
        {
            int mid = pro_l + pro_r >> 1;

            if (pos[x] == mid)
                break;
            if (pos[x] < mid)
            {
                pro_r = mid - 1;
                GG.push_back(mid);
            } else
            {
                pro_l = mid + 1;
                LL.push_back(mid);
            }
        }

        int rem_greater = n - x, rem_lesser = x - 1;
        int lesser = 0, greaterr = 0;
        for (int xx : LL)
            if (p[xx] > x)
                greaterr++;
            else
                rem_lesser--;
        for (int xx : GG)
            if (p[xx] < x)
                lesser++;
            else
                rem_greater--;

        int mn = min(lesser, greaterr);
        int res = 2 * mn;
        rem_greater -= mn;
        rem_lesser -= mn;
        lesser -= mn;
        greaterr -= mn;
        cout << ((greaterr > 0 && rem_lesser < greaterr) || (lesser > 0 && rem_greater < lesser) ? -1 : res + 2 * max(greaterr, lesser)) << ' ';
    }
    cout << '\n';
}
