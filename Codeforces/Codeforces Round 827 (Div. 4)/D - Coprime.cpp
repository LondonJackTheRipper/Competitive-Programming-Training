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
int GCD(int a, int b) { return (b == 0 ? a : GCD(b, a % b)); }

void solve()
{
    int n; cin >> n;
    vector<int> cnt(1002, 0);
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;

        cnt[x] = max(cnt[x], i);
    }

    int res = -1;
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
        {
            if (cnt[i] == 0 || cnt[j] == 0 || GCD(i, j) != 1)
                continue;

            res = max(res, cnt[i] + cnt[j]);
        }

    cout << res << '\n';
}
