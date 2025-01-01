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

    a.erase(unique(a.begin(), a.end()), a.end());
    int tmp = 0;
    for (int i = 1; i < (int)a.size() - 1; i++)
        tmp += ((a[i - 1] < a[i] && a[i] < a[i + 1]) || (a[i - 1] > a[i] && a[i] > a[i + 1]));

    cout << (int)a.size() - tmp << '\n';
}
