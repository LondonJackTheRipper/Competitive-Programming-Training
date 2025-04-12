#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
    int a[2 * n + 1];
    vector<int> pos[n + 1];
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    vector<bool> adj(n + 1, 0);
    for (int i = 1; i <= n; i++)
        adj[i] = (pos[i][1] - pos[i][0] == 1);

    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i])
            continue;
        set<int> se;
        for (int j = max(1, pos[i][0] - 1); j <= min(2 * n, pos[i][0] + 1); j++)
            if (j != pos[i][0])
                se.insert(a[j]);
        for (int j = max(1, pos[i][1] - 1); j <= min(2 * n, pos[i][1] + 1); j++)
            if (j != pos[i][1])
                se.insert(a[j]);
        for (int x : se)
        {
            if (adj[x])
                continue;
            vector<int> proc = {pos[i][0], pos[i][1]};
            for (int p : pos[x])
                proc.push_back(p);
            sort(proc.begin(), proc.end());
            bool flag = true;
            for (int i = 0; i < 4; i++)
            {
                int cnt = 0;
                if (i == 0) cnt++; else cnt += (proc[i] != proc[i - 1] + 1);
                if (i == 3) cnt++; else cnt += (proc[i] != proc[i + 1] - 1);
                if (cnt == 2)
                    flag = false;
            }
            res += (flag == true);
        }
    }

    cout << res / 2 << '\n';
}
