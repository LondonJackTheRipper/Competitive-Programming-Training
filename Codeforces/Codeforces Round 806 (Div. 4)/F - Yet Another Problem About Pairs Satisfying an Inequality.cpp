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
    vector<int> arr, idx;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        if (x < i)
        {
            arr.push_back(x);
            idx.push_back(i);
        }
    }
    sort(idx.begin(), idx.end());

    ll res = 0;
    for (int x : arr)
        res += (lower_bound(idx.begin(), idx.end(), x) - idx.begin());

    cout << res << '\n';
}