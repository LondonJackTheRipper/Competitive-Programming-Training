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
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll give = 0;
    vector<ll> res(n, 0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        int add = 0;
        while (!pq.empty() && pq.top().first - give <= 0)
        {
            add += (pq.top().first - give == 0);
            pq.pop();
        }
        pq.push({a[i] + add + pq.size() + give, i});
        if (i != n - 1)
            give++;
    }
    while (!pq.empty())
    {
        res[pq.top().second] = pq.top().first - give;
        pq.pop();
    }

    for (int i = 0; i < n; i++)
        cout << res[i] << ' ';
    cout << '\n';
}
