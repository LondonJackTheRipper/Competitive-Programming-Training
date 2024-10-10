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
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    if (a[0] == a[n - 1])
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
        if (a[i] != a[n - 1])
            v1.push_back(a[i]);
        else
            v2.push_back(a[i]);

    cout << v1.size() << ' ' << v2.size() << '\n';
    for (int x : v1) cout << x << ' '; cout << '\n';
    for (int x : v2) cout << x << ' '; cout << '\n';
}
