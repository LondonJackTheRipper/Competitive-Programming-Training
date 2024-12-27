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

int n, m, k;
int c[2 * maxn];

int cnt[maxn], boxes[maxn], total[maxn];
int total_boxes = 0, ans = 0;

void add(int x, int v)
{
    ans -= min(k * boxes[x], total[x]);
    total_boxes -= boxes[x];
    boxes[x] -= (cnt[x] + k - 1) / k;
    cnt[x] += v;
    boxes[x] += (cnt[x] + k - 1) / k;
    total_boxes += boxes[x];
    ans += min(k * boxes[x], total[x]);
}

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];

        c[i + n] = c[i];
        total[c[i]]++;
    }

    int r = 1;
    for (int l = 1; l <= n; l++)
    {
        while (r < l + n && total_boxes < m)
            add(c[r++], 1);

        cout << ans << '\n';

        add(c[l], -1);
    }
}
