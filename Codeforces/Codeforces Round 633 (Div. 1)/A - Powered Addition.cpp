#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
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
const int maxn = 1e5 + 9;

int arr[maxn];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i], arr[i] += 1e9;

    int cur = 0;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            int gap = arr[i - 1] - arr[i];
            for (int j = 0; j < 32; j++)
                if (gap >> j & 1)
                    cur |= (1 << j);

            arr[i] = arr[i - 1];
        }
    }

    int res = 0;
    for (int i = 0; i < 32; i++)
        if (cur >> i & 1)
            res = i + 1;
    cout << res << '\n';
}
