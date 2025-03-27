#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// main program

void solve()
{
    int n, k; cin >> n >> k;
    
    vector<int> cnt(n + 1, 0), res;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > 0; j--)
            if (i != j && (i % k == j % k) && cnt[j] == 0)
            {
                cnt[j] = 1;
                res.push_back(j);
                break;
            }
    }
    
    if (res.size() != n)
        cout << -1 << '\n';
    else
    {
        for (int x : res) 
            cout << x << ' ';
        cout << '\n';
    }
}
