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

int GCD(int a, int b) { return (b == 0 ? a : GCD(b, a % b)); }

void solve()
{
    int n, m; cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int cur = a[1];
    for (int i = 2; i <= n; i++) cur = GCD(cur, a[i]);
    
    while (m--)
    {
        int idx, v; cin >> idx >> v;
        
        a[idx] /= v;
        cur = GCD(cur, a[idx]);
        cout << cur << '\n';
    }
}
