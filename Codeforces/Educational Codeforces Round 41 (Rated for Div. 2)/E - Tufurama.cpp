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
struct FenwickTree
{
    int n;
    vector<int> bits;

    FenwickTree(int n) : n(n) { bits.resize(n + 1, 0); }

    void update(int pos, int val)
    {
        for (; pos <= n; pos += (pos & (-pos)))
            bits[pos] += val;
    }

    int query(int pos)
    {
        int res = 0;
        for (; pos > 0; pos -= (pos & (-pos)))
            res += bits[pos];
        return res;
    }
    int query(int l, int r) { return query(r) - query(l - 1); }
};

void solve()
{
    int n; cin >> n;
    int a[n + 1];
    vector<int> proc, lim[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        proc.push_back(a[i]);
        lim[min(i - 1, a[i])].push_back(i);
    }

    sort(proc.begin(), proc.end());
    map<int, int> comp;
    int cur = 0;
    for (int x : proc)
        if (comp[x] == 0)
            comp[x] = ++cur;

    ll ans = 0;
    FenwickTree bit(cur);
    for (int i = 1; i <= n; i++)
    {
        bit.update(comp[a[i]], 1);

        for (int j : lim[i])
            if (j > i)
            {
                int pos = lower_bound(proc.begin(), proc.end(), j) - proc.begin();

                if (pos == (int)proc.size())
                    continue;
                int val = proc[pos];
                ans += bit.query(comp[val], cur);
            }
    }

    cout << ans << '\n';
}
