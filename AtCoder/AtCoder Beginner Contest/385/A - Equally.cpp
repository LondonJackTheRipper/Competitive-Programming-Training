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
    vector<int> a(3);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    if (a[0] == a[1] && a[1] == a[2])
    {
        cout << "Yes\n";
        return;
    }

    cout << (a[0] + a[1] == a[2] ? "Yes\n" : "No\n");
}
