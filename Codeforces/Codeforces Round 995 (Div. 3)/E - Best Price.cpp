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
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    vector<int> proc;
    for (int &x : a) cin >> x, proc.push_back(x);
    for (int &x : b) cin >> x, proc.push_back(x);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll res = n * a[0];
    proc.erase(unique(proc.begin(), proc.end()), proc.end());
    for (int x : proc)
    {
        int lef = lower_bound(b.begin(), b.end(), x) - b.begin();
        int rig = lower_bound(a.begin(), a.end(), x) - a.begin();
        rig = n - rig;

        if (n - lef - rig > k) continue;

        res = max(res, 1ll * (n - lef) * x);
    }

    cout << res << '\n';
}
