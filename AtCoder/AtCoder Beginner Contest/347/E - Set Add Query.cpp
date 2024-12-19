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

int n, q;
ll pre[maxn];
int cnt[maxn];
vector<int> pos[maxn];

void solve()
{
    cin >> n >> q;
    int sz = 0;
    for (int i = 1; i <= q; i++)
    {
        int x; cin >> x;

        pos[x].push_back(i);
        pre[i] = pre[i - 1];
        if (cnt[x] == 0)
        {
            sz++;
            cnt[x] = 1;
            pre[i] += sz;
        }
        else
        {
            sz--;
            cnt[x] = 0;
            pre[i] += sz;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        ll ans = 0;

        pos[i].push_back(q + 1);
        int turns = 1;
        for (int j = 1; j < pos[i].size(); j++)
        {
            turns ^= 1;
            if (turns == 1)
                continue;

            int a = pos[i][j - 1] - 1;
            int b = pos[i][j] - 1;

            if (a <= b)
                ans += pre[b] - pre[a];
        }

        cout << ans << ' ';
    }
    cout << '\n';
}
