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
    set<int> adj[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            char c; cin >> c;

            if (c == '1' && i < j)
                adj[i].insert(j);
        }
    vector<int> res, used(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if ((int)adj[j].size() == 0 && used[j] == 0)
            {
                used[j] = 1;
                res.push_back(j);
                break;
            }
        int val = res.back();
        for (int j = 0; j < n; j++)
            if (used[j] == 0 && adj[j].find(val) != adj[j].end())
                adj[j].erase(val);
    }

    reverse(res.begin(), res.end());
    for (int x : res)
        cout << x + 1 << ' ';
    cout << '\n';
}
