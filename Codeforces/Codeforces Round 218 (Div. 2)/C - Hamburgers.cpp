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
    string s; cin >> s;
    int n_b, n_s, n_c; cin >> n_b >> n_s >> n_c;
    int p_b, p_s, p_c; cin >> p_b >> p_s >> p_c;
    int r_b = 0, r_s = 0, r_c = 0;
    ll r; cin >> r;
    for (char c : s)
        if (c == 'B') r_b++; else
        if (c == 'S') r_s++; else
                      r_c++;

    ll res = -1;
    ll left = 0, right = 1e14;
    while (left <= right)
    {
        ll mid = left + right >> 1;

        ll req = max(0ll, 1ll * r_b * mid - n_b) * p_b + max(0ll, 1ll * r_s * mid - n_s) * p_s + max(0ll, 1ll * r_c * mid - n_c) * p_c;

        if (req <= r)
        {
            res = mid;
            left = mid + 1;
        } else
            right = mid - 1;
    }

    cout << res << '\n';
}
