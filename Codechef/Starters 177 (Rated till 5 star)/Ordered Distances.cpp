#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// main program
const int maxn = 100;

int n;
vector<int> pos(1000, 0);
int x[maxn + 1], y[maxn + 1];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        pos[x[i]] = i;
    }
    for (int i = 1; i <= n; i++) cin >> y[i];
    
    vector<pair<int, int>> proc;
    for (int i = 1; i <= n; i++)
        proc.push_back({abs(x[i] - y[1]), x[i]});
    sort(proc.begin(), proc.end());
    for (int i = 1; i <= n; i++)
        if (proc[i - 1].second != y[i])
        {
            cout << -1 << '\n';
            return;
        }
    cout << pos[y[1]] << '\n';
}
