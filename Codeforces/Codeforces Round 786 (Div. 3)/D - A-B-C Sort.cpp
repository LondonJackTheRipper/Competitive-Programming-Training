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
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (n != 1)
    {
        if (n % 2 == 1)
            sort(a + 2, a + 4);
        else
            sort(a + 1, a + 3);
    }
    int st = (n % 2 == 1 ? 4 : 3);
    for (int i = st; i <= n; i += 2)
        if (a[i] > a[i + 1])
            swap(a[i], a[i + 1]);

    for (int i = 2; i <= n; i++)
        if (a[i] < a[i - 1])
        {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}
