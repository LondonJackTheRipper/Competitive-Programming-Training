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
pair<int, int> proc(int x)
{
    return {x % 10, (x / 10) <= (x % 10)};
}

void solve()
{
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    pair<int, int> fi = proc(a[0]);

    int prev = (fi.second == true ? fi.first : a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] < prev && a[i] / 10 < prev)
        {
            cout << "NO\n";
            return;
        }

        if (a[i] > 9 && proc(a[i]).second == true && a[i] / 10 >= prev)
            prev = a[i] % 10;
        else
            prev = a[i];
    }

    cout << "YES\n";
}
