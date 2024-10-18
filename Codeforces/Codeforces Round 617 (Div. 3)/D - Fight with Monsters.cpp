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

void solve()
{
    int n, a, b, k; cin >> n >> a >> b >> k;
    int h[n + 1];
    vector<int> proc;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];

        if ((h[i] % (a + b)) == 0)
            proc.push_back(max(0, ((a + b + a - 1) / a) - 1));
        else
            proc.push_back(max(0, (((h[i] % (a + b)) + a - 1) / a) - 1));
    }

    sort(proc.begin(), proc.end());
    int res = 0;
    for (int x : proc)
    {
        if (k - x < 0) break;
        k -= x;
        res++;
    }

    cout << res << '\n';
}
