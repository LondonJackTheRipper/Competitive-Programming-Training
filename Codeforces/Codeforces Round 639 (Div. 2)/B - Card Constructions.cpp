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
    int x; cin >> x;

    int i = 0;
    ll cur = 0;
    vector<int> pre;
    while (cur <= x)
    {
        if (cur != 0) pre.push_back(cur);
        i++;
        cur = cur + 2 * i + i - 1;
    }

    int res = 0;
    for (int i = pre.size() - 1; i >= 0; i--)
        if (x >= pre[i])
        {
            res += (x / pre[i]);
            x %= pre[i];
        }

    cout << res << '\n';
}
