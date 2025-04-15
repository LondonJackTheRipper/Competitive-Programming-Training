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

    solve();

    return 0;
}

// main program
const int mod = 1e9;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int sub(int a, int b) { a -= b; if (a < 0) a += mod; return a; }

void solve()
{
    int n, k; cin >> n >> k;

    if (n <= k - 1)
    {
        cout << 1 << '\n';
        return;
    }

    vector<int> res(n + 1, 1), prefix(n + 1, 1);
    for (int i = 1; i < k; i++)
        prefix[i] += prefix[i - 1];
    for (int i = k; i <= n; i++)
    {
        res[i] = sub(prefix[i - 1], (i - 1 - k >= 0 ? prefix[i - 1 - k] : 0));
        prefix[i] = add(prefix[i - 1], res[i]);
    }

    cout << res[n] << '\n';
}
