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
    vector<pair<int, int>> a(n);
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(b, b + n);
    sort(a.begin(), a.end());
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[a[i].second] = b[i];

    for (int i = 0; i < n; i++)
        cout << res[i] << ' ';
    cout << '\n';
}
