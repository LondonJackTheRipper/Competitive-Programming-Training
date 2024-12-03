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
    if (n < 4)
    {
        cout << -1 << '\n';
        return;
    }

    int div = n / 4, rem = n % 4;
    vector<int> ans;
    for (int i = 0; i < div; i++)
        if (i % 2 == 0)
        {
            ans.push_back(4 * i + 3); ans.push_back(4 * i + 1);
            ans.push_back(4 * i + 4); ans.push_back(4 * i + 2);
        } else
        {
            ans.push_back(4 * i + 2); ans.push_back(4 * i + 4);
            ans.push_back(4 * i + 1); ans.push_back(4 * i + 3);
        }
    for (int i = 4 * div + 1; i <= n; i++) if (i != 4 * div + 2) ans.push_back(i);
    if (rem > 1) ans.insert(ans.begin() + (div % 2 == 1 ? 4 * div - 2 : 4 * (div - 1)) + 1, 4 * div + 2);

    for (int x : ans) cout << x << ' '; cout << '\n';
}
