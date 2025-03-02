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

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// main program

void solve()
{
    int n; cin >> n;

    if (n % 2 == 1)
    {
        if (n < 26)
            cout << -1 << '\n';
        else
        {
            vector<int> ans(n + 1, 0);
            int cnt = 4;
            ans[1] = ans[10] = ans[26] = 1;
            ans[27] = ans[23] = 2;
            ans[24] = ans[25] = 3;
            for (int i = 2; i < 10; i += 2)
                ans[i] = ans[i + 1] = cnt++;
            for (int i = 11; i < 23; i += 2)
                ans[i] = ans[i + 1] = cnt++;
            for (int i = 28; i <= n; i += 2)
                ans[i] = ans[i + 1] = cnt++;
            for (int i = 1; i <= n; i++)
                cout << ans[i] << ' ';
            cout << '\n';
        }
        return;
    }

    for (int i = 1; i <= n; i += 2)
        cout << i << ' ' << i << ' ';
    cout << '\n';
}
