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
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++)
    {
        char c; cin >> c;
        num[i] = c - '0';
    }

    if (num[0] == 9)
    {
        vector<int> res;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 10; j++)
            {
                if ((num[i] + j) % 10 == 1)
                {
                    res.push_back(j);
                    if (i != 0) num[i - 1] += (num[i] + j) / 10;
                    break;
                }
            }
        }
        reverse(res.begin(), res.end());
        for (int x : res) cout << x; cout << '\n';
    } else
    {
        vector<int> res(n);
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            int j = n - i - 1;
            if (i == j)
                res[i] = 0;
            else
            {
                int base = (i == 0 ? 9 : max(num[i], num[j]));
                res[i] = base - num[i];
                res[j] = base - num[j];
            }
        }
        for (int x : res) cout << x; cout << '\n';
    }
}
