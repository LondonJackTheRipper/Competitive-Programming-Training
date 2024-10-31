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
int r[maxn], ans[maxn], same_quarrel[maxn];

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> r[i];
    for (int i = 1; i <= k; i++)
    {
        int a, b; cin >> a >> b;

        if (r[a] > r[b]) same_quarrel[a]++;
        if (r[b] > r[a]) same_quarrel[b]++;
    }

    vector<pair<int, int>> tmp_r;
    for (int i = 1; i <= n; i++)
        tmp_r.push_back({r[i], i});
    sort(tmp_r.begin(), tmp_r.end());
    map<int, int> cnt;

    for (int i = 1; i <= n; i++)
    {
        int idx = tmp_r[i - 1].second;
        int skill = tmp_r[i - 1].first;

        ans[idx] = (i - 1 - cnt[skill]) - same_quarrel[idx];

        cnt[skill]++;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}
