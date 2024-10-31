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

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(m);
    for (int &x : a) cin >> x;
    int Fedor; cin >> Fedor;

    int res = 0;
    for (int x : a)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += ((Fedor >> j & 1) ^ (x >> j & 1));

        res += (cnt <= k);
    }

    cout << res << '\n';
}
