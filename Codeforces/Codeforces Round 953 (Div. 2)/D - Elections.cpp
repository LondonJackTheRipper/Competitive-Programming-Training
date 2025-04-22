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

void solve()
{
    int n; cin >> n;
    ll c; cin >> c;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    ll prefix = 0;
    int pos_mx = max_element(a, a + n) - a, mx = a[pos_mx];
    priority_queue<pair<ll, int>> pq;
    for (int i = 1; i < n; i++)
        pq.push({a[i], i});
    for (int i = 0; i < n; i++)
    {
        int res = 1e9;
        // No help
        if ((i == 0 && a[0] + c >= mx) || (i == pos_mx && a[0] + c < mx))
            res = 0;
        // With help;
        ll tmp = a[i];
        tmp += prefix + c;
        int ans = i;
        if (tmp < mx)
        {
            while (!pq.empty())
            {
                if (pq.top().second <= i)
                    pq.pop();
                else
                {
                    ans++;
                    tmp += pq.top().first;
                    break;
                }
            }
        }
        if (tmp >= mx)
            res = min(res, ans);

        prefix += a[i];

        cout << res << ' ';
    }
    cout << '\n';
}
