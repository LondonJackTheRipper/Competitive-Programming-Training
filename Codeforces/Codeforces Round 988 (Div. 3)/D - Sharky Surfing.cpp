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
    int n, m, l; cin >> n >> m >> l;
    vector<ll> pre(m);
    vector<int> x(m), v(m);
    vector<pair<int, int>> hurdles(n);
    for (pair<int, int> &p : hurdles) cin >> p.first >> p.second; // l r
    for (int i = 0; i < m; i++) cin >> x[i] >> v[i];
    pre[0] = v[0];
    for (int i = 1; i < m; i++) pre[i] = v[i] + pre[i - 1];

    int res = 0;
    int prev = 0;
    ll cur_power = 1;
    priority_queue<int> pq;
    for (pair<int, int> p : hurdles)
    {
        int l = p.first, r = p.second, dist = r - l + 2;
        int pos1 = lower_bound(x.begin(), x.end(), l) - x.begin(); pos1--;
        int pos2 = upper_bound(x.begin(), x.end(), prev) - x.begin();
        for (int j = pos2; j <= pos1; j++)
            pq.push(v[j]);

        while (cur_power < dist && !pq.empty())
        {
            cur_power += pq.top();
            res++;
            pq.pop();
        }
        if (cur_power < dist)
        {
            cout << -1 << '\n';
            return;
        }

        prev = p.second;
    }

    cout << res << '\n';
}
