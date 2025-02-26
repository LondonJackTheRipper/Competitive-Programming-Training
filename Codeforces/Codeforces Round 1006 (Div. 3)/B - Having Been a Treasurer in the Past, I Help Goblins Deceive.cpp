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
    string s; cin >> s;
    vector<int> cnt(2, 0);
    for (char c : s)
    {
        if (c == '-')
            cnt[0]++;
        else
            cnt[1]++;
    }

    cout << 1ll * cnt[1] * (cnt[0] / 2) * (cnt[0] - cnt[0] / 2) << '\n';
}
