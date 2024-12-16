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
    vector<int> cnt(3, 0);
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        cnt[x % 3]++;
    }

    int res = 0;
    for (int i = 0; i < 3; i++)
    {
        if (cnt[i] <= n / 3) continue;

        for (int j = 0; j < 3; j++)
            if (j != i && cnt[i] > n / 3 && cnt[j] < n / 3)
            {
                int sub = min(cnt[i] - (n / 3), n / 3 - cnt[j]);

                cnt[j] += sub;
                cnt[i] -= sub;
                res += sub * (j > i ? j - i : 3 - i + j);
            }
    }

    cout << res << '\n';
}
