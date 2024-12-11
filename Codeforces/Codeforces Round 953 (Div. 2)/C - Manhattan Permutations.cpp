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
    ll k; cin >> k;

    ll lim = 0;
    for (int i = n - 1; i > 0; i -= 2)
        lim += i;
    lim *= 2;

    if (k % 2 == 1 || k > lim)
    {
        cout << "No\n";
        return;
    }
    k /= 2;

    int res[n + 1];
    for (int i = 1; i <= n; i++) res[i] = i;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n - i + 1 - i < k)
        {
            k -= n - i + 1 - i;
            swap(res[i], res[n - i + 1]);
        } else
        {
            swap(res[i], res[i + k]);
            break;
        }
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << '\n';
}
