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
const ll oo = 1e18;

void solve()
{
    int n, k; cin >> n >> k; k--;
    pair<int, int> a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i].first;
    for (int i = 1; i <= n; i++) cin >> a[i].second;
    sort(a + 1, a + n + 1);

    ll cur = 0;
    priority_queue<int> pq;
    for (int i = 1; i <= k; i++)
    {
        cur += a[i].second;
        pq.push(a[i].second);
    }
    ll mn[n + 1];
    mn[0] = 0;
    mn[k] = cur;
    for (int i = k + 1; i <= n; i++)
    {
        if (!pq.empty() && a[i].second < pq.top())
        {
            cur = cur - pq.top() + a[i].second;
            pq.pop();
            pq.push(a[i].second);
        }
        mn[i] = cur;
    }

    ll ans = oo;
    for (int i = k + 1; i <= n; i++)
        ans = min(ans, a[i].first * (mn[i - 1] + a[i].second));
    cout << ans << '\n';
}
