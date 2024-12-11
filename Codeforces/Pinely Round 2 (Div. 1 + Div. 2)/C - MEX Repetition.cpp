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
    k %= (n + 1);

    ll sum = 0;
    vector<int> res(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        sum += x;

        if (i + k <= n)
            res[i + k] = x;
        else
        if (i + k != n + 1)
            res[k - 1 - n + i] = x;
    }
    int MEX = 1ll * n * (n + 1) / 2 - sum;

    for (int i = 1; i <= n; i++)
        cout << (res[i] == -1 ? MEX : res[i]) << ' ';
    cout << '\n';
}
