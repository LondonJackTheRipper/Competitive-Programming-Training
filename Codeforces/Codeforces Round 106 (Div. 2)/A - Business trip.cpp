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
    int k; cin >> k;
    int a[12];
    for (int i = 0; i < 12; i++) cin >> a[i];
    sort(a, a + 12, greater<int>());

    int res = 0, cur = 0;
    for (int i = 0; i < 12; i++)
    {
        if (cur >= k) break;
        cur += a[i];
        res++;
    }
    cout << (cur >= k ? res : -1) << '\n';
}
