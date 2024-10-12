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

pair<int, int> a[maxn];
int n;

long double dist(int x1, int y1, int x2, int y2)
{
    return (long double)sqrt((long double)(x1 - x2) * (x1 - x2) + (long double)(y1 - y2) * (y1- y2));
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;

    long double res = dist(0, 0, a[1].first, a[1].second) + dist(a[n].first, a[n].second, 0, 0);
    for (int i = 1; i < n; i++) res += dist(a[i].first, a[i].second, a[i + 1].first, a[i + 1].second);
    cout << fixed << setprecision(6) << res << '\n';
}

