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
    int n, s; cin >> n >> s;
    vector<int> pos;
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;

        if (x == 1) pos.push_back(i);
        total += x;
    }

    if (total < s)
    {
        cout << "-1\n";
        return;
    }

    int mn = 1e9;
    for (int i = 0; i < pos.size() - s + 1; i++)
    {
        int j = i + s - 1;

        int ans = pos[j] - pos[i] + 1;
        ans += (i == 0 ? pos[i] - 1 : pos[i] - pos[i - 1] - 1);
        ans += (j == pos.size() - 1 ? n - pos[j] : pos[j + 1] - pos[j] - 1);

        mn = min(mn, n - ans);
    }

    cout << mn << '\n';
}
