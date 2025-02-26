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
    int k; cin >> k;

    vector<pair<int, int>> ans;
    int rem = 500, cnt = 0, cnt1 = 0;
    while (k > 0)
    {
        for (int i = rem; i > 0; i--)
            if (1ll * i * (i - 1) / 2 <= k)
            {
                k -= 1ll * i * (i - 1) / 2;
                for (int j = 0; j < i; j++)
                    ans.push_back({-(1e9) + cnt1++, (1e9) - cnt});
                cnt++;
                break;
            }
    }
    if (ans.empty())
    ans.push_back({0, 0});

    cout << ans.size() << '\n';
    for (pair<int, int> it : ans)
        cout << it.first << ' ' << it.second << '\n';
}
