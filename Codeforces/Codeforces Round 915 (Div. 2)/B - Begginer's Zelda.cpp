#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve();
signed main()
{
    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// main program

void solve()
{
    int n; cin >> n;

    vector<int> deg(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res += (deg[i] == 1);

    cout << (res + 1) / 2 << '\n';
}

