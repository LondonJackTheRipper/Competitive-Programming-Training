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
    int n, m;
    cin >> n >> m;
    int a[n];
    pair<int, int> b[m];
    for (int i = 0; i < n; i++) cin >>a[i];
    for (int i = 0; i < m; i++) cin >> b[i].first, b[i].second = i;
    vector<int> ans(m, -1);
    sort(b, b + m, greater<pair<int, int>>());
    int it = 0;
    for (int i = 0; i < n; i++)
    {
        while (it < m && b[it].first >= a[i])
        {
            ans[b[it].second] = i + 1;
            it++;
        }
    }

    for (int i = 0; i < m; i++) cout << ans[i] << '\n';
}
