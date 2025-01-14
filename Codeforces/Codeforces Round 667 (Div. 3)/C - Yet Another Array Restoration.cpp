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
    int n, x, y; cin >> n >> x >> y;

    int ans_mx = 0;
    vector<int> res[y - x + 1];
    vector<int> res_mx(y - x + 1, 1e9);
    for (int d = 1; d <= y - x; d++)
    {
        if ((y - x) % d != 0)
            continue;

        vector<int> ans = {x, y};
        int tmp = n - 2;
        int num = ((y - x) / d) - 1;
        if (num > tmp)
            continue;
        for (int i = x + d; i < y; i += d)
            ans.push_back(i);
        tmp -= num;
        int mx = y;
        num = x - d;
        while (tmp > 0 && num > 0)
        {
            ans.push_back(num);
            num -= d;
            tmp--;
        }
        num = y + d;
        while (tmp > 0)
        {
            ans.push_back(num);
            mx = num;
            num += d;
            tmp--;
        }

        for (int x : ans)
            res[d].push_back(x);
        if (mx < res_mx[ans_mx])
            ans_mx = d;
        res_mx[d] = mx;
    }

    for (int x : res[ans_mx])
        cout << x << ' ';
    cout << '\n';
}
