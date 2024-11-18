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

    solve();

    return 0;
}

// main program

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<pair<char, int>> block;
    int cur = 0;
    char cur_c = '#';
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c != cur_c)
        {
            if (cur != 0) block.push_back({cur_c, cur});
            cur_c = c;
            cur = 1;
        } else
            cur++;
    }
    if (cur != 0) block.push_back({cur_c, cur});
    vector<int> block1;
    for (int i = 0; i < block.size(); i++)
        if (block[i].first == '1')
            block1.push_back(i);
    int pos1 = block1[k - 2], pos2 = block1[k - 1];

    for (int i = 0; i < block.size(); i++)
    {
        if (i == pos2) continue;

        if (i == pos1)
            for (int j = 0; j < block[i].second + block[pos2].second; j++)
                cout << 1;
        else
            for (int j = 0; j < block[i].second; j++)
                cout << block[i].first;
    }
    cout << '\n';
}
