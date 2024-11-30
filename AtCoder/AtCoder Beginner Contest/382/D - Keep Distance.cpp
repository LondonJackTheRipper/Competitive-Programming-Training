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
int n, m;
vector<vector<int>> ans;

void recur(int cnt, int prev, vector<int> cur)
{
    if (cnt == n)
    {
        ans.push_back(cur);
        return;
    }

    for (int i = prev + 10; i <= m; i++)
    {
        int rem = n - cnt;
        if (m - prev >= 10 * rem)
        {
            cur.push_back(i);
            recur(cnt + 1, i, cur);
            cur.pop_back();
        }
    }
}

void solve()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        vector<int> st = {i};
        recur(1, i, st);
    }

    cout << ans.size() << '\n';
    for (vector<int> x : ans)
    {
        for (int val : x) cout << val << ' ';
        cout << '\n';
    }
}
