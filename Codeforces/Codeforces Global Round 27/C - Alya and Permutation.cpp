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

    if (n % 2 == 0)
    {
        vector<int> used(n + 1, 0);
        vector<int> res;
        res.push_back(n);
        used[n] = 1;
        vector<int> bit(20, 0);
        int highest = 0;
        for (int j = 0; j < 20; j++)
            if (n >> j & 1)
            {
                highest = j;
                bit[j] = 1;
            }
        int num = 0;
        for (int i = 0; i < highest; i++)
            if (bit[i] == 0)
                num += (1 << i);
        used[num] = 1;
        int tmp = num;
        res.push_back(num);
        for (int i = 0; i < highest; i++)
            if (bit[i] == 1 && used[num + (1 << i)] == 0)
            {
                num += (1 << i);
                break;
            }
        if (num != tmp)
        {
            used[num] = 1;
            res.push_back(num);
        } else
        {
            used[1] = 1;
            used[3] = 1;
            used[num - 1] = 1;
            res.push_back(num - 1);
            res.push_back(1);
            res.push_back(3);
        }
        for (int i = 1; i <= n; i++) if (used[i] == 0) res.push_back(i);
        reverse(res.begin(), res.end());
        cout << (1 << (highest + 1)) - 1 << '\n';
        for (int x : res) cout << x << ' ';
        cout << '\n';
    } else
    {
        vector<int> used(n + 1, 0);
        vector<int> res;
        used[n] = 1;
        res.push_back(n);
        used[n - 1] = 1;
        res.push_back(n - 1);
        used[1] = used[3] = 1;
        res.push_back(1);
        res.push_back(3);
        for (int i = 1; i <= n; i++) if (used[i] == 0) res.push_back(i);
        reverse(res.begin(), res.end());
        cout << n << '\n';
        for (int x : res) cout << x << ' ';
        cout << '\n';
    }
}
