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
const long double pi = 3.1415926536;

long double area(int r) { return pi * r * r; }

void solve()
{
    int n; cin >> n;
    vector<int> radius;
    for (int i = 0; i < n; i++)
    {
        int r; cin >> r;
        radius.push_back(r);
    }

    sort(radius.begin(), radius.end());
    long double res = 0;
    for (int i = n - 1; i >= 0; i -= 2)
    {
        int prev_r = (i == 0 ? 0 : radius[i - 1]);
        int now_r = radius[i];
        res += area(now_r) - area(prev_r);
    }

    cout << fixed << setprecision(4) << res << '\n';
}
