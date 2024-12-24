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
    int n, m, k; cin >> n >> m >> k;
    int a[m];
    for (int i = 0; i < m; i++) cin >> a[i];
    vector<int> know(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        int x; cin >> x;
        know[x] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        if (k < n - 1)
        {
            cout << 0;
            continue;
        }
        if (k == n)
        {
            cout << 1;
            continue;
        }
        cout << (know[a[i]] == 0 ? 1 : 0);
    }

    cout << '\n';
}
