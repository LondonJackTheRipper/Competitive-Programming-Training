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
    ll total = 0, even = 0, odd = 0, num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
        if (i % 2 == 0) even += a[i], num1++; else odd += a[i], num2++;
    }
    ll fix = total / n;
    if (total % n != 0)
    {
        cout << "NO\n";
        return;
    }
    if (even != fix * num1 || odd != fix * num2)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
