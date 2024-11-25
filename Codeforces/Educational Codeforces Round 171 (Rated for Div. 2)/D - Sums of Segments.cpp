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
const int maxn = 3e5 + 9;

int n, q;
int a[maxn];
ll pre[maxn], prefix[maxn];
ll ID[maxn], pre_compute[maxn];

ll compute(int id, int l, int r) // id <= l && r <= n
{
    if (l > r || id > l || r > n) return 0ll;
    return prefix[r] - prefix[l - 1] - 1ll * (r - l + 1) * pre[id - 1];
}

ll segment(int l, int r)
{
    if (l > r) return 0ll;
    return pre_compute[r] - pre_compute[l - 1];
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        prefix[i] = prefix[i - 1] + pre[i];
        ID[i] = ID[i - 1] + n - i + 1;
    }
    for (int i = 1; i <= n; i++)
        pre_compute[i] = pre_compute[i - 1] + compute(i, i, n);

    cin >> q;
    while (q--)
    {
        ll l, r; cin >> l >> r;

        int L = lower_bound(ID, ID + n, l) - ID;
        int R = lower_bound(ID, ID + n, r) - ID;

        cout << segment(L, R) - compute(L, L, L + l - ID[L - 1] - 2) - compute(R, R + r - ID[R - 1], n) << '\n';
    }
}
