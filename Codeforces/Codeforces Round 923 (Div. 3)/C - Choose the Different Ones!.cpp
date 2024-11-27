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
    int n, m, k; cin >> n >> m >> k;
    vector<int> used(k + 1, 0), choose;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (x <= k && used[x] == 0)
        {
            used[x] = 1;
            choose.push_back(x);
        }
    }
    vector<int> cnt(k + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        if (x <= k) cnt[x]++;
    }
    for (int i = 1; i <= k; i++)
        if (cnt[i] == 0 && used[i] == 0)
        {
            cout << "NO\n";
            return;
        }

    int sz = choose.size();
    for (int x : choose)
    {
        if (sz <= k / 2) break;
        if (cnt[x] > 0)
            sz--;
    }

    cout << (sz == k / 2 ? "YES\n" : "NO\n");
}
