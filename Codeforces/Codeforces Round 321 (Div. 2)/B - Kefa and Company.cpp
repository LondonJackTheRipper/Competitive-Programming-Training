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
const int maxn = 1e5 + 9;

int n, d;
pair<int, int> ms[maxn];

void solve()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> ms[i].first >> ms[i].second;

    sort(ms + 1, ms + n + 1);
    ll cur = 0, res = 0;
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        while (j <= n && ms[j].first - ms[i].first < d)
        {
            cur += ms[j].second;
            j++;
        }
        res = max(res, cur);
        cur -= ms[i].second;
    }

    cout << res << '\n';
}
