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
int next(int x) { return x + (x % 10); }

void solve()
{
    int n; cin >> n;
    int a[n];
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 5 == 0)
        {
            flag = true;
            a[i] = next(a[i]);
        }
    }

    if (flag == true)
        cout << (*min_element(a, a + n) == *max_element(a, a + n) ? "YES\n" : "NO\n");
    else
    {
        for (int i = 0; i < n; i++)
            while (a[i] % 10 != 2)
                a[i] = next(a[i]);
        int reach = *max_element(a, a + n);
        bool res = true;
        for (int i = 0; i < n; i++)
            if ((reach - a[i]) % 20 != 0)
                res = false;

        cout << (res == true ? "YES\n" : "NO\n");
    }
}
