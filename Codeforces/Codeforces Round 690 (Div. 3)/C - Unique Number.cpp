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

void backtrack(int pos, int num, int cur, int sum, int x, vector<int>& vis, vector<int>& digit)
{
    if (pos == num)
    {
        if (sum == x)
            digit.push_back(cur);
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (vis[i] == 1) continue;

        vis[i] = 1;
        backtrack(pos + 1, num, cur * 10 + i, sum + i, x, vis, digit);
        vis[i] = 0;
    }
}

void solve()
{
    int x; cin >> x;

    if (x > 45)
    {
        cout << -1 << '\n';
        return;
    }

    int num = 0, cur = 0;
    for (int i = 9; i > 0; i--)
    {
        cur += i;
        if (cur >= x)
        {
            num = 9 - i + 1;
            break;
        }
    }

    vector<int> vis(10, 0), digit;
    backtrack(0, num, 0, 0, x, vis, digit);
    sort(digit.begin(), digit.end());
    cout << digit.front() << '\n';
}
