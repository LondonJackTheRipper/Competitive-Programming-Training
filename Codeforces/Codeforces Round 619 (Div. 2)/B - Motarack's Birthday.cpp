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
const int oo = 0x3f3f3f3f;
const int maxn = 1e5 + 1;

int n;
int a[maxn];

int compute(int k)
{
    int mx = 0;
    for (int i = 2; i <= n; i++)
        mx = max(mx, abs((a[i] == -1 ? k : a[i]) - (a[i - 1] == -1 ? k : a[i - 1])));
    return mx;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int k = 0, mn = oo;
    int mn_val = oo, mx_val = -oo;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != -1)
            continue;

        if (i != 1 && a[i - 1] != -1)
        {
            mn_val = min(mn_val, a[i - 1]);
            mx_val = max(mx_val, a[i - 1]);
        }
        if (i != n && a[i + 1] != -1)
        {
            mn_val = min(mn_val, a[i + 1]);
            mx_val = max(mx_val, a[i + 1]);
        }
    }
    if (mn_val == oo)
        mn = 0;
    else
    {
        int avg = (mn_val + mx_val) / 2;
        mn = compute(avg);
        k = avg;
        if (compute(avg + 1) < mn)
        {
            mn = compute(avg + 1);
            k++;
        }
    }

    cout << mn << ' ' << k << '\n';
}
