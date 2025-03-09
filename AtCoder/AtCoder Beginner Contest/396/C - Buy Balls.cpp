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
    vector<int> b(n), w(m);
    for (int &x : b) cin >> x;
    for (int &x : w) cin >> x;
    sort(b.begin(), b.end(), greater<int>());
    vector<ll> prefix(b.begin(), b.end());
    for (int i = 1; i < n; i++)
        prefix[i] += prefix[i - 1];
    vector<ll> maxx(prefix.begin(), prefix.end());
    for (int i = n - 2; i >= 0; i--)
        maxx[i] = max(maxx[i], maxx[i + 1]);
    sort(w.begin(), w.end(), greater<int>());

    ll mx = 0, W = 0;
    int lim = min(n, m);
    for (int i = 0; i < lim; i++)
    {
        W += w[i];
        mx = max(mx, maxx[i] + W);
    }
    ll pre = 0;
    for (int i = 0; i < n; i++)
    {
        pre += b[i];
        mx = max(mx, pre);
    }

    cout << mx << '\n';
}
