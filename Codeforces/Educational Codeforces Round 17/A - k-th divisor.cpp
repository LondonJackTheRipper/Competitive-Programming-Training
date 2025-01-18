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
    ll n; cin >> n;
    int k; cin >> k;

    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i != 0)
            continue;

        divs.push_back(i);
        if (i * i != n)
            divs.push_back(n / i);
    }
    sort(divs.begin(), divs.end());

    if (k > divs.size())
        cout << -1 << '\n';
    else
        cout << divs[k - 1] << '\n';
}
