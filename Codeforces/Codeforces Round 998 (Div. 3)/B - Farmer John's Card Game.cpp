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
    int n, m; cin >> n >> m;
    vector<int> cows[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x; cin >> x;
            cows[i].push_back(x);
        }
        sort(cows[i].begin(), cows[i].end());
    }

    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++)
        pos.push_back({cows[i].front(), i});
    sort(pos.begin(), pos.end());

    int cur = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (cows[pos[j].second][i] != cur)
            {
                cout << -1 << '\n';
                return;
            }
            cur++;
        }

    for (int i = 0; i < n; i++)
        cout << pos[i].second + 1 << ' ';
    cout << '\n';
}
