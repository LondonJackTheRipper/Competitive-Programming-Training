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
    int n; cin >> n;
    ll s; cin >> s;
    ll sum = 0;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    s %= sum;
    if (s == 0)
    {
        cout << "Yes\n";
        return;
    }

    map<ll, int> mp;
    mp[0] = 1;
    ll pre = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        int pos = (i > n ? i - n : i);

        pre += arr[pos];
        if (mp[pre - s])
        {
            cout << "Yes\n";
            return;
        }

        mp[pre - arr[pos]] = 1;
    }

    cout << "No\n";
}
