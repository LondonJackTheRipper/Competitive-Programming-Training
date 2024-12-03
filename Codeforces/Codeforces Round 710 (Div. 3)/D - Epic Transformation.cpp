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
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x]++;
    }

    priority_queue<pair<int, int>> pq;
    for (auto it : mp)
        pq.push({it.second, it.first});

    int sz = 0;
    while (!pq.empty())
    {
        if (pq.size() == 1) break;

        int a = pq.top().second, cnt_a = pq.top().first; pq.pop();
        int b = pq.top().second, cnt_b = pq.top().first; pq.pop();
        int rem = (cnt_b + 1) / 2;

        sz += 2 * rem;
        if (cnt_a > rem) pq.push({cnt_a - rem, a});
        if (cnt_b > rem) pq.push({cnt_b - rem, b});
    }

    cout << n - sz << '\n';
}
