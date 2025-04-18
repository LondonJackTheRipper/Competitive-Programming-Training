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

    vector<int> pos[10];
    for (int i = 0; i < (int)s.length(); i++)
        pos[s[i] - '0'].push_back(i);

    string res = "";
    int last = -1;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < (int)pos[i].size(); j++)
        {
            int idx = pos[i][j];
            if (idx > last)
                res.push_back(char('0' + i));
            else
                res.push_back(char('0' + min(i + 1, 9)));

            last = max(last, idx);
        }

    sort(res.begin(), res.end());
    cout << res << '\n';
}
