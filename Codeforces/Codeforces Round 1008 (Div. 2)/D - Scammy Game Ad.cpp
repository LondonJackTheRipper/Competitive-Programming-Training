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
    int n; cin >> n;
    vector<char> c1(n), c2(n);
    vector<int> num1(n), num2(n);
    for (int i = 0; i < n; i++)
        cin >> c1[i] >> num1[i] >> c2[i] >> num2[i];

    vector<ll> dpl(n + 1, 1), dpr(n + 1, 1);
    ll res = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        dpl[i] = dpl[i + 1];
        if (c1[i] == 'x')
            dpl[i] += (num1[i] - 1) * max(dpl[i + 1], dpr[i + 1]);
        else
            res += num1[i] * max(dpl[i + 1], dpr[i + 1]);

        dpr[i] = dpr[i + 1];
        if (c2[i] == 'x')
            dpr[i] += (num2[i] - 1) * max(dpl[i + 1], dpr[i + 1]);
        else
            res += num2[i] * max(dpl[i + 1], dpr[i + 1]);
    }
    res += dpl[0] + dpr[0];

    cout << res << '\n';
}
