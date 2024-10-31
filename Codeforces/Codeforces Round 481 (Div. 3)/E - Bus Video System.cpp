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
    int n, w; cin >> n >> w;

    int prefix = 0;
    int left = 2e9, right = -2e9;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        prefix += x;
        left = min(left, prefix);
        right = max(right, prefix);
    }

    left = (left < 0 ? -left : 0);
    right = (right <= 0 ? w : w - right);

    cout << max(0, right - left + 1) << '\n';
}
