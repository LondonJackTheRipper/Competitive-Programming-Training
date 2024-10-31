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

    vector<int> block;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        char c; cin >> c;
        if (c == 'x')
            cur++;
        else
        if (cur != 0)
        {
            block.push_back(cur);
            cur = 0;
        }
    }
    if (cur != 0) block.push_back(cur);

    int res = 0;
    for (int x : block)
        res += max(0, x - 2);

    cout << res << '\n';
}
