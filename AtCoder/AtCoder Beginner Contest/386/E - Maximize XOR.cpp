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
const int maxn = 2e5 + 9;

int n, k;
ll res = 0;
ll a[maxn], suff[maxn];

void backtrack(int pos = 0, int chosen = 0, ll cur = 0)
{
    if (n - pos < k - chosen)
        return;
    if (k - chosen == n - pos)
    {
        res = max(res, cur ^ suff[pos]);
        return;
    }
    if (chosen == k)
    {
        res = max(res, cur);
        return;
    }

    backtrack(pos + 1, chosen, cur);
    if (chosen < k)
        backtrack(pos + 1, chosen + 1, cur ^ a[pos]);
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i >= 0; i--)
        suff[i] = a[i] ^ suff[i + 1];

    backtrack();

    cout << res << '\n';
}
