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
    vector<int> primes = {2, 3, 5, 7};
    vector<int> cnt(10, 0);
    for (int i = 0; i < n; i++)
    {
        char c; cin >> c;
        int x = (c - '0');
        if (x < 2) continue;
        for (int j = 2; j <= x; j++)
        {
            int y = j;
            for (int p : primes)
            while (y % p == 0)
            {
                cnt[p]++;
                y /= p;
            }
        }
    }

    vector<int> res;
    for (int i = 9; i > 1; i--)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            res.push_back(i);
            for (int k = i - 1; k > 1; k--)
            {
                int tmp = k;
                for (int p : primes)
                    while (tmp % p == 0)
                    {
                        cnt[p]--;
                        tmp /= p;
                    }
            }
        }
    }
    sort(res.begin(), res.end(), greater<int>());

    for (int x : res)
        cout << x;
    cout << '\n';
}
