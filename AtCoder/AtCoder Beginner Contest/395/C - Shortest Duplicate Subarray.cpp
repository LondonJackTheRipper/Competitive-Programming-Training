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
    vector<int> last(1000001, -1);

    int ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        if (last[x] != -1)
            ans = min(ans, i - last[x] + 1);
        last[x] = i;
    }

    cout << (ans == (int)1e9 ? -1 : ans) << '\n';
}
