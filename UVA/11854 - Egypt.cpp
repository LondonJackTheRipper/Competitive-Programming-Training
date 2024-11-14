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
    vector<int> v(3, 0);

    while (cin >> v[0] >> v[1] >> v[2])
    {
        if (v[0] == 0 && v[1] == 0 && v[2] == 0)
            break;

        sort(v.begin(), v.end());
        cout << (v[0] * v[0] + v[1] * v[1] == v[2] * v[2] ? "right\n" : "wrong\n");
    }
}
