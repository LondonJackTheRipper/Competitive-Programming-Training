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

vector<int> digit(int n)
{
    vector<int> res;
    while (n)
    {
        res.push_back(n % 10);
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve()
{
    int n; cin >> n;

    ll res = 0;
    while (n)
    {
        vector<int> di = digit(n);
        if (di.size() == 1)
        {
            res += n;
            break;
        }
        int num = 0;
        for (int i = 0; i < di.size() - 1; i++)
            num = num * 10 + di[i];
        num *= 10;
        res += num;
        n = n - num + (num / 10);
    }

    cout << res << '\n';
}
