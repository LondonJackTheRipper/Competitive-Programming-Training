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
const int maxn = 1e6 + 9;

int lg[maxn];
void init(int n)
{
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
}

struct sparse
{
    int n;
    vector<int> sp[25];

    sparse(int n, int *pre) : n(n)
    {
        for (int i = 0; i < 25; i++) sp[i].resize(n + 5, 0);
        for (int i = 1; i <= n; i++) sp[0][i] = pre[i];
        for (int i = 1; i < 21; i++)
            for (int j = 1; j + (1 << i) - 1 <= n; j++)
                sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
    }

    int query(int l, int r)
    {
        int LOG = lg[r - l + 1];
        return min(sp[LOG][l], sp[LOG][r - (1 << LOG) + 1]);
    }
};

void solve()
{
    init(1e6);

    string s; cin >> s;
    int n = (int)s.length();
    int pre[n + 1];
    vector<int> cluster[2 * n + 1];
    cluster[n].push_back(0);
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + (s[i - 1] == '(' ? 1 : -1);
        cluster[pre[i] + n].push_back(i);
    }

    int ans = 0, cnt = 0;
    sparse sp(n, pre);
    for (int i = 0; i <= 2 * n; i++)
    {
        if (cluster[i].empty()) continue;

        for (int j = 0; j < cluster[i].size(); j++)
        {
            int l = j + 1, r = cluster[i].size() - 1;

            int res = -1;
            while (l <= r)
            {
                int mid = l + r >> 1;

                if (sp.query(cluster[i][j] + 1, cluster[i][mid]) - pre[cluster[i][j]] >= 0)
                {
                    res = mid;
                    l = mid + 1;
                } else
                    r = mid - 1;
            }
            if (res == -1) continue;

            if (ans == cluster[i][res] - cluster[i][j])
                cnt++;
            else
            if (ans < cluster[i][res] - cluster[i][j])
            {
                ans = cluster[i][res] - cluster[i][j];
                cnt = 1;
            }
        }
    }

    if (ans == 0)
    {
        cout << "0 1\n";
        return;
    }

    cout << ans << ' ' << cnt << '\n';
}
