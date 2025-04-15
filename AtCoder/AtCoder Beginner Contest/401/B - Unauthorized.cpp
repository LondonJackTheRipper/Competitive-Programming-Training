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

void solve()
{
    int n; cin >> n;

    int state1 = 0, res = 0;
    string state2 = "";
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;

        if (s == "login" || s == "logout")
        {
            state1 = (s == "login" ? 1 : 0);
            continue;
        }
        else
            state2 = s;


        res += (state2 == "private" && state1 == 0);
    }

    cout << res << '\n';
}
