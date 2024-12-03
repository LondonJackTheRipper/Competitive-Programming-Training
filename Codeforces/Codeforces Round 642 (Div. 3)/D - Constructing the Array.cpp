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
struct block
{
    int st, l;

    block() = default;
    block(int st, int l) : st(st), l(l) {};

    bool operator > (const block& other) const
    {
        if (l == other.l) return st > other.st;
        return l < other.l;
    }
};

void solve()
{
    int n; cin >> n;
    priority_queue<block, vector<block>, greater<block>> pq;
    pq.push({1, n});

    int ans[n + 1];
    int times = 0;
    while (!pq.empty())
    {
        int st = pq.top().st, l = pq.top().l;
        pq.pop();

        int mid = 2 * st + l - 1 >> 1;
        ans[mid] = ++times;
        if (st < mid) pq.push({st, mid - st});
        if (mid < st + l - 1) pq.push({mid + 1, st + l - 1 - mid});
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}
