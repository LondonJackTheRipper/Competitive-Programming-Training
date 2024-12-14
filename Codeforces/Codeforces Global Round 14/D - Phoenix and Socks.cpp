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
    int n, l, r; cin >> n >> l >> r;
    vector<int> L(n + 1, 0), R(n + 1, 0);
    for (int i = 0; i < l; i++) { int x; cin >> x; L[x]++; }
    for (int i = 0; i < r; i++) { int x; cin >> x; R[x]++; }

    for (int i = 1; i <= n; i++)
    {
        int need = min(L[i], R[i]);
        l -= need;
        r -= need;
        L[i] -= need;
        R[i] -= need;
    }

    if (l < r)
    {
        swap(l, r);
        swap(L, R);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = L[i] / 2;
        int can = min(l - r, 2 * tmp);

        res += can / 2;
        l -= can;
    }

    res += (l - r) / 2 + (l + r) / 2;
    cout << res << '\n';
}
