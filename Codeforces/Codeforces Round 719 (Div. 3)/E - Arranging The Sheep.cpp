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
    string s; cin >> s;

    vector<ll> pre(n + 1, 0);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pre[i] = (i == 0 ? 0 : pre[i - 1]);
        cnt[i] = (i == 0 ? 0 : cnt[i - 1]);
        if (s[i] == '*')
        {
            pre[i] += i;
            cnt[i]++;
        }
    }

    ll mn = 1e18;
    for (int i = 0; i < n; i++)
    {
        ll l = pre[i], r = pre[n - 1] - pre[i];
        ll num_l = cnt[i], num_r = cnt[n - 1] - cnt[i];

        mn = min(mn, num_l * i - l - num_l * (num_l - 1) / 2 + r - num_r * i - num_r * (num_r + 1) / 2);
    }

    cout << mn << '\n';
}
