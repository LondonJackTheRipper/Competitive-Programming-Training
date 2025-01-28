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
const int maxn = 1e5 + 9;

int l[maxn], r[maxn], changes[maxn];
int n, m, q;

bool proc(int mid)
{
    vector<int> prefix(maxn, 0);
    for (int i = 1; i <= mid; i++)
        prefix[changes[i]]++;
    for (int i = 2; i <= n; i++)
        prefix[i] += prefix[i - 1];

    for (int i = 1; i <= m; i++)
    {
        int qr = prefix[r[i]] - prefix[l[i] - 1];

        if (qr > r[i] - l[i] + 1 - qr)
            return true;
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> l[i] >> r[i];
    cin >> q;
    for (int i = 1; i <= q; i++)
        cin >> changes[i];

    int LEFT = 1, RIGHT = q;
    int res = -1;
    while (LEFT <= RIGHT)
    {
        int mid = LEFT + RIGHT >> 1;

        if (proc(mid))
        {
            res = mid;
            RIGHT = mid - 1;
        } else
            LEFT = mid + 1;
    }

    cout << res << '\n';
}
