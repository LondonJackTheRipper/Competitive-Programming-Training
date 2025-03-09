#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return abs(a.second) <= abs(b.second);
}

void solve()
{
    int n, k; cin >> n >> k;
    vector<pair<int, int>> proc(n);
    for (int i = 0; i < n; i++) cin >> proc[i].first;
    for (int i = 0; i < n; i++) cin >> proc[i].second;
    sort(proc.begin(), proc.end(), cmp);

    ll moves = 0, bullets = 0;
    for (pair<int, int> it : proc)
    {
        int a = it.first, x = it.second;
        if (a <= bullets)
        {
            bullets -= a;
            continue;
        }

        a -= bullets;
        ll need = (1ll * a + k - 1) / k;
        if (abs(x) - moves - need < 0)
        {
            cout << "NO\n";
            return;
        }
        moves += need;
        bullets = 1ll * need * k - a;
    }

    cout << "YES\n";
}
