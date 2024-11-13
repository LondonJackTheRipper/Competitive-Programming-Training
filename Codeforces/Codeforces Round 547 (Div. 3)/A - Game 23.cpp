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
    int n, m; cin >> n >> m;

    vector<int> cnt_n(4, 0), cnt_m(4, 0);
    while (n % 2 == 0) cnt_n[2]++, n /= 2;
    while (n % 3 == 0) cnt_n[3]++, n /= 3;
    while (m % 2 == 0) cnt_m[2]++, m /= 2;
    while (m % 3 == 0) cnt_m[3]++, m /= 3;

    if (n != m || cnt_n[2] > cnt_m[2] || cnt_n[3] > cnt_m[3])
    {
        cout << -1 << '\n';
        return;
    }
    cout << cnt_m[2] - cnt_n[2] + cnt_m[3] - cnt_n[3] << '\n';
}
