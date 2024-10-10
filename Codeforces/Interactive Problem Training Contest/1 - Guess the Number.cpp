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

    int t = 1;
    while (t--) solve();

    return 0;
}

// main program
string ask(int x)
{
    cout << x << endl;
    string res; cin >> res;
    return res;
}

void answer(int x)
{
    cout << "! " << x << endl;
}

void solve()
{
    int l = 1, r = 1e6;
    int ans = -1;

    while (l <= r)
    {
        int mid = l + r >> 1;

        string res = ask(mid);
        if (res == "<")
            r = mid - 1;
        else
        {
            ans = mid;
            l = mid + 1;
        }
    }

    answer(ans);
}
