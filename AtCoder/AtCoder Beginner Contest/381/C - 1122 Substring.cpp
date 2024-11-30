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
    int n; cin >> n;
    string s; cin >> s;

    vector<int> block_1, pos1, block_2, pos2;
    int cur = 0;
    for (int i = 0; i < (int)s.length(); i++)
    {
        char c = s[i];
        if (c == '1')
            cur++;
        else
            if (cur != 0)
            {
                block_1.push_back(cur);
                pos1.push_back(i - 1);
                cur = 0;
            }
    }
    if (cur != 0)
    {
        block_1.push_back(cur);
        pos1.push_back(n - 1);
    }
    cur = 0;
    for (int i = 0; i < (int)s.length(); i++)
    {
        char c = s[i];
        if (c == '2')
            cur++;
        else
            if (cur != 0)
            {
                block_2.push_back(cur);
                pos2.push_back(i - cur);
                cur = 0;
            }
    }
    if (cur != 0)
    {
        block_2.push_back(cur);
        pos2.push_back(n - cur);
    }

    int res = 1;
    for (int i = 0; i < (int)s.length(); i++)
    {
        char c = s[i];
        if (c != '/') continue;
        int left = lower_bound(pos1.begin(), pos1.end(), i - 1) - pos1.begin();
        int right = lower_bound(pos2.begin(), pos2.end(), i + 1) - pos2.begin();
        if (left == pos1.size() || right == pos2.size()) continue;
        if (pos1[left] != i - 1 || pos2[right] != i + 1) continue;
        res = max(res, 1 + 2 * min(block_1[left], block_2[right]));
    }

    cout << res << '\n';
}
