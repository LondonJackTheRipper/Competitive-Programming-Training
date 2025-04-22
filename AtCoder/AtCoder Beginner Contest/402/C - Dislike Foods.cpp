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

    solve();

    return 0;
}

// main program

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> dishes[n + 1];
    for (int i = 0; i < m; i++)
    {
        int k; cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x; cin >> x;
            dishes[x].push_back(i + 1);
        }
    }
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<int> ans(n, 0);
    set<int> se;
    for (int i = 1; i <= m; i++)
        se.insert(i);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = se.size();

        for (int x : dishes[b[i]])
            if (se.find(x) != se.end())
                se.erase(x);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
}
