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
bool prime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return (n > 1);
}

void solve()
{
    int n; cin >> n;

    if (n % 2 == 1)
    {
        cout << (n == 1 ? "FastestFinger\n" : "Ashishgup\n");
        return;
    }

    int x = 0, tmp = n;
    while (tmp % 2 == 0) x++, tmp /= 2;
    if (tmp == 1)
    {
        cout << (x > 1 ? "FastestFinger\n" : "Ashishgup\n");
        return;
    }

    if (x > 1)
    {
        cout << "Ashishgup\n";
        return;
    }

    cout << (prime(tmp) == true ? "FastestFinger\n" : "Ashishgup\n");
}
