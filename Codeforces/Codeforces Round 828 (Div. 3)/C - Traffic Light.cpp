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
    char c; cin >> c;
    string s; cin >> s;

    vector<int> pos;
    for (int i = 0; i < n; i++)
        if (s[i] == 'g')
            pos.push_back(i + 1);

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        char cur = s[i - 1];
        if (cur != c) continue;

        int it = lower_bound(pos.begin(), pos.end(), i) - pos.begin();
        res = max(res, (it == pos.size() ? n - i + pos[0] : pos[it] - i));
    }

    cout << res << '\n';
}
