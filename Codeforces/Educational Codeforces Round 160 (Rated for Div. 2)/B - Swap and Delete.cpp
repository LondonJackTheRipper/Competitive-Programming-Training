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
    string s; cin >> s;
    int n = s.length();

    vector<int> cnt(2, 0);
    for (char c : s)
        cnt[c - '0']++;

    int res = n;
    vector<int> cur(2, 0);
    for (int i = 0; i < n; i++)
    {
        cur[s[i] - '0']++;

        if (cur[0] <= cnt[1] && cur[1] <= cnt[0])
            res = min(res, cnt[1] - cur[0] + cnt[0] - cur[1]);
    }

    cout << res << '\n';
}
