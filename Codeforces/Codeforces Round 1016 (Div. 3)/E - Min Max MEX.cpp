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

int n, k;
int a[maxn];

bool check(int lim)
{
    unordered_map<int, int> mp;
    int cur = 0, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < lim && mp[a[i]] < cur + 1)
        {
            mp[a[i]]++;
            sum++;
        }
        if (sum == lim)
        {
            sum = 0;
            cur++;
        }
    }

    return (cur >= k);
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int res = 0;
    int l = 1, r = n + 1;
    while (l <= r)
    {
        int mid = l + r >> 1;

        if (check(mid))
        {
            res = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }

    cout << res << '\n';
}
