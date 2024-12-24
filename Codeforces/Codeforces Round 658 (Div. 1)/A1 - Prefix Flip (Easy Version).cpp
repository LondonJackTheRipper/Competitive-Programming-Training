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
    string a, b; cin >> a >> b;

    vector<int> res;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == b[i]) continue;

        if (a[i] != a[0])
        {
            res.push_back(1);
            a[0] = (a[0] == '1' ? '0' : '1');
        }
        res.push_back(i + 1);
        for (int j = 0; j <= i; j++)
            a[j] = (a[j] == '0' ? '1' : '0');
        reverse(a.begin(), a.begin() + i + 1);
    }

    cout << res.size() << ' ';
    for (int x : res)
        cout << x << ' ';
    cout << '\n';
}
