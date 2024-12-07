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
ll C2(int n) { return 1ll * n * (n - 1) / 2; }
ll C3(int n) { return 1ll * n * (n - 1) * (n - 2) / 6; }

void solve()
{
    int n; cin >> n;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        cnt[x]++;
    }

    ll res = 0;
    int num = 0;
    for (int i = 0; i <= n; i++)
    {
        if (cnt[i] > 1) res += C2(cnt[i]) * num;
        if (cnt[i] > 2) res += C3(cnt[i]);

        num += cnt[i];
    }

    cout << res << '\n';
}
