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
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

void solve()
{
    int n, k; cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i - 1].first;
        v[i - 1].first %= k;
        if (v[i - 1].first == 0) v[i - 1].first = k;
        v[i - 1].second = i;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
        cout << v[i].second << ' ';
    cout << '\n';
}
