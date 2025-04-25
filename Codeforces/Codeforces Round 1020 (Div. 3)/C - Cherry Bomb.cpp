#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
    int n, k;
    cin >> n >> k;
    int a[n], b[n];
    int sum = -1;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] != -1)
            sum = (sum == -1 ? a[i] + b[i] : min(sum, a[i] + b[i]));
    }

    if (sum != -1)
    {
        for (int i = 0; i < n; i++)
            if ((b[i] != -1 && a[i] + b[i] != sum) || (b[i] == -1 && (a[i] > sum || sum - a[i] > k)))
            {
                cout << 0 << '\n';
                return;
            }
        cout << 1 << '\n';
    } else
    {
        int mx = *max_element(a, a + n), mn = *min_element(a, a + n);
        cout << k - (mx - mn) + 1 << '\n';
    }
}
