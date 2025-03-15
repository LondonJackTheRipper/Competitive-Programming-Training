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
    string s; cin >> s;
    int n = s.length();
    vector<int> pos[26];
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        pos[c - 'a'].push_back(i);
    }
    vector<int> lg(n + 1, 0);
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;

    int res = 1e9;
    for (int i = 0; i < 26; i++)
    {
        if (pos[i].empty())
            continue;

        int cur_res = 0;
        for (int j = 0; j < pos[i].size(); j++)
        {
            if (j == 0 && pos[i][j] != 0) cur_res = max(cur_res, lg[pos[i][j]] + 1);
            if (j == pos[i].size() - 1 && pos[i][j] != n - 1) cur_res = max(cur_res, lg[n - 1 - pos[i][j]] + 1);
            if (j > 0 && pos[i][j] - pos[i][j - 1] != 1)
                cur_res = max(cur_res, lg[pos[i][j] - pos[i][j - 1] - 1] + 1);
        }
        res = min(res, cur_res);
    }

    cout << res << '\n';
}
