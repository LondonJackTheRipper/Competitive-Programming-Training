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
    int d, sum; cin >> d >> sum;
    vector<pair<int, int>> cons(d);
    int lef = 0, rig = 0;
    for (pair<int, int>& it : cons)
    {
        cin >> it.first >> it.second;

        lef += it.first;
        rig += it.second;
    }

    if (sum < lef || rig < sum)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    sum -= lef;
    for (pair<int, int> it : cons)
    {
        int brack = it.second - it.first;

        cout << it.first + min(brack, sum) << ' ';
        sum -= min(brack, sum);
    }
}
