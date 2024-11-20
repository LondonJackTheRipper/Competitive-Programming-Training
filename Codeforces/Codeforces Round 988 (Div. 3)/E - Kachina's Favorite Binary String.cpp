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
int ask(int l, int r)
{
    if (l >= r) return 0;
    cout << "? " << l << ' ' << r << endl;
    int res; cin >> res;
    return res;
}

void rep(string s, bool can)
{
    (can == false ? cout << "! IMPOSSIBLE" << endl : cout << "! " << s << endl);
}

void solve()
{
    int n; cin >> n;

    int fi = 1, prev;
    string cur = "";
    for (fi; fi <= n; fi++)
    {
        int res = ask(1, fi);
        prev = res;

        if (res != 0)
        {
            for (int i = 0; i < fi - res - 1; i++) cur.push_back('1');
            for (int i = 0; i < res; i++) cur.push_back('0');
            cur.push_back('1');
            break;
        }
    }

    if (cur.empty())
    {
        rep("", false);
        return;
    }

    for (int i = fi + 1; i <= n; i++)
    {
        int res = ask(1, i);

        cur.push_back(res > prev ? '1' : '0');
        prev = res;
    }

    rep(cur, true);
}
