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
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int left = 0, right = n - 1;
    while (left < n && a[left] == a[0]) left++; left--;
    while (right > 0 && a[right] == a[n - 1]) right--; right++;

    if (left >= right)
        cout << 0 << '\n';
    else
        cout << (a[0] == a[n - 1] && n != 1 ? right - left - 1 : n - 1 - max(left, n - 1 - right)) << '\n';
}
