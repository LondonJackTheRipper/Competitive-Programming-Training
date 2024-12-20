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
    int n; cin >> n;
    vector<int> cnt(6, 0);
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        cnt[x]++;
    }

    if (cnt[0] == 0)
    {
        cout << -1 << '\n';
        return;
    }

    if (cnt[5] >= 9)
    {
        for (int i = 0; i < 9 * (cnt[5] / 9); i++)
            cout << 5;
        while (cnt[0]--)
            cout << 0;
        cout << '\n';
    } else
        cout << 0 << '\n';
}
