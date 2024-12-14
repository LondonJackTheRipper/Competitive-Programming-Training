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
    vector<ll> pre(n + 1, 0), pre_even(n + 1, 0), pre_odd(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;

        pre[i] = pre[i - 1] + x;
        pre_even[i] = pre_even[i - 1] + (i % 2 == 0 ? x : 0);
        pre_odd[i] = pre_odd[i - 1] + (i % 2 == 1 ? x : 0);
    }

    map<ll, int> even;
    even[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (even[pre[i] - 2 * pre_even[i]] == 1)
        {
            cout << "YES\n";
            return;
        }

        if (i % 2 == 0)
            even[pre[i - 1] - 2 * pre_even[i - 1]] = 1;
    }

    map<ll, int> odd;
    odd[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (odd[pre[i] - 2 * pre_odd[i]] == 1)
        {
            cout << "YES\n";
            return;
        }

        if (i % 2 == 1)
            odd[pre[i - 1] - 2 * pre_odd[i - 1]] = 1;
    }

    cout << "NO\n";
}
