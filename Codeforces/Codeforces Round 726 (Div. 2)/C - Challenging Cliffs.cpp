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
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x]++;
    }

    vector<pair<int, int>> proc;
    int pos = -1;
    for (auto it : mp)
    {
        proc.push_back({it.first, it.second});
        if (it.second > 1)
            pos = proc.size() - 1;
    }

    if (pos != -1)
    {
        proc[pos].second -= 2;
        cout << proc[pos].first << ' ';
        for (int i = pos + 1; i < proc.size(); i++)
            for (int j = 0; j < proc[i].second; j++) cout << proc[i].first << ' ';
        for (int i = 0; i <= pos; i++)
            for (int j = 0; j < proc[i].second; j++) cout << proc[i].first << ' ';
        cout << proc[pos].first << '\n';
    } else
    {
        int a = -1, b = -1, res = 1e9;
        for (int i = 1; i < proc.size(); i++)
            if (proc[i].first - proc[i - 1].first < res)
            {
                res = proc[i].first - proc[i - 1].first;
                a = i - 1;
                b = i;
            }
        cout << proc[a].first << ' ';
        for (int i = b + 1; i < proc.size(); i++) cout << proc[i].first << ' ';
        for (int i = 0; i < a; i++) cout << proc[i].first << ' ';
        cout << proc[b].first << '\n';
    }
}
