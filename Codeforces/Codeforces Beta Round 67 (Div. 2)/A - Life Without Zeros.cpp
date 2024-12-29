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
int trans(int x)
{
    string res = "";
    while (x)
    {
        if (x % 10 != 0)
            res.push_back(char((x % 10) + '0'));
        x /= 10;

    }
    reverse(res.begin(), res.end());
    int ans = 0;
    for (char c : res)
        ans = ans * 10 + (c - '0');
    return ans;
}

void solve()
{
    int a, b; cin >> a >> b;
    int c = a + b;

    cout << (trans(c) == trans(a) + trans(b) ? "YES\n" : "NO\n");
}
